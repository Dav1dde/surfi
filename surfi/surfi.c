/* See LICENSE file for copyright and license details. */
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <webkit/webkit.h>


typedef struct SurfiClient {
	GtkWidget *window;
	GtkWidget *view;

	void *userptr;
} SurfiClient;

// abcdefghijklmnopqrstuvqxyz

// TODO:
static void error(const char *errstr, ...);

bool surfi_init(void);
bool surfi_poll(void);

SurfiClient* surfi_client_new(int width, int height);
void surfi_client_set_size(SurfiClient *c, int width, int height);
void surfi_client_set_userptr(SurfiClient *c, void *ptr);


static void error(const char *errstr, ...) {
	//TODO
}


/*
 * Initializes surfi.
 * This is basically a call to gtk_init_check.
 *
 * RETURNS: true if call was succesful otherwise false
 *
 */
bool surfi_init(void)
{
	return gtk_init_check(NULL, NULL);
}


/*
 * This updates everything related to surfi *and* gtk.
 * You can omit a call to surfi_poll if you're running
 * the gtk mainloop your own.
 *
 * RETURNS: true if there were events which needed processing, otherwise false
 */
bool surfi_poll(void)
{
	if(gtk_events_pending()) {
		gtk_main_iteration();
		return true;
	}

	return false;
}


/*
 * Initializes a new SurfiClient representing the offscreen webview.
 *
 * RETURNS: SurfiClient*
 */
SurfiClient* surfi_client_new(int width, int height)
{
	SurfiClient *c;

	if(!(c = calloc(1, sizeof(SurfiClient))))
		error("Malloc failed");

	c->window = gtk_offscreen_window_new();
	c->view = webkit_web_view_new();
	gtk_widget_set_size_request(c->view, width, height);
	gtk_container_add (GTK_CONTAINER(c->window), c->view);
	gtk_widget_show_all(c->window);

	return c;
}

/*
 * Sets the size of the offscreen webview.
 * 
 */
void surfi_client_set_size(SurfiClient* c, int width, int height)
{
	gtk_widget_set_size_request(c->view, width, height);
}


/*
 * Set a userptr for a SurfiClient.
 *
 */
void surfi_client_set_userptr(SurfiClient *c, void *ptr)
{
	c->userptr = ptr;
}

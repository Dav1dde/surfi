/* See LICENSE file for copyright and license details. */
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <glib-object.h>
#include <webkit/webkit.h>

#include "surfi/surfi.h"


static void error(const char *errstr, ...) {
	//TODO
}

bool surfi_init(void)
{
	return gtk_init_check(NULL, NULL);
}


bool surfi_poll(void)
{
	if(gtk_events_pending()) {
		gtk_main_iteration();
		return true;
	}

	return false;
}

SurfiClient* surfi_client_new(int width, int height)
{
	SurfiClient *c;

	if(!(c = calloc(1, sizeof(SurfiClient)))) {
		error("Malloc failed");
		return NULL;
	}

	c->window = gtk_offscreen_window_new();
	c->view = webkit_web_view_new();
	gtk_widget_set_size_request(c->view, width, height);
	gtk_container_add (GTK_CONTAINER(c->window), c->view);
	gtk_widget_show_all(c->window);

	return c;
}

void surfi_client_set_size(SurfiClient* c, int width, int height)
{
	gtk_widget_set_size_request(c->view, width, height);
}


void surfi_client_set_userptr(SurfiClient *c, void *ptr)
{
	c->userptr = ptr;
}

void* surfi_client_get_userptr(SurfiClient *c)
{
	return c->userptr;
}
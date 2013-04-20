/* See LICENSE file for copyright and license details. */
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <glib-object.h>
#include <webkit/webkit.h>

#include "surfi/surfi.h"


#define SET_FUNCPTR(EXP) \
	if(EXP) { \
		EXP = callback; \
		return; \
	} \
	EXP = callback;


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

	if(!(c = calloc(1, sizeof(SurfiClient))))
		error("Malloc failed");

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

void* surfi_client_get_userptr(SurfiClient* c)
{
	return c->userptr;
}


bool _surfi_client_set_callback_close_web_view(WebKitWebView *view, SurfiClient *client)
{
	return (*client->on_close_web_view)(client);
}

void surfi_client_set_callback_close_web_view(SurfiClient* client, bool(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_close_web_view);
	g_signal_connect(client->view, "close-web-view", G_CALLBACK(_surfi_client_set_callback_close_web_view), client);
}

bool _surfi_client_set_callback_console_message(WebKitWebView *view, char *message, int line, char *source_id, SurfiClient *client)
{
	return (*client->on_console_message)(client, message, line, source_id);
}

void surfi_client_set_callback_console_message(SurfiClient* client, bool(*callback)(SurfiClient *client,
		char *message, int line, char *source_id))
{
	SET_FUNCPTR(client->on_console_message);
	g_signal_connect(client->view, "console-message", G_CALLBACK(_surfi_client_set_callback_console_message), client);
}

bool _surfi_client_set_callback_context_menu(WebKitWebView *view, GtkWidget *default_menu, WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard, SurfiClient *client)
{
	return (*client->on_context_menu)(client, default_menu, hit_test_result, triggered_with_keyboard);
}

void surfi_client_set_callback_context_menu(SurfiClient* client, bool(*callback)(SurfiClient *client,
		GtkWidget *default_menu, WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard))
{
	SET_FUNCPTR(client->on_context_menu);
	g_signal_connect(client->view, "context-menu", G_CALLBACK(_surfi_client_set_callback_context_menu), client);
}

void _surfi_client_set_callback_copy_clipboard(WebKitWebView *view, SurfiClient* client)
{
	(*client->on_copy_clipboard)(client);
}

void surfi_client_set_callback_copy_clipboard(SurfiClient* client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_copy_clipboard);
	g_signal_connect(client->view, "copy-clipboard", G_CALLBACK(_surfi_client_set_callback_copy_clipboard), client);
}

void _surfi_client_set_callback_create_plugin_widget(WebKitWebView *view, char *mime_type, char *uri, GHashTable *param, SurfiClient *client)
{
	(*client->on_create_plugin_widget)(client, mime_type, uri, param);
}

void surfi_client_set_callback_create_plugin_widget(SurfiClient* client, void(*callback)(SurfiClient *client, char *mime_type, char *uri, GHashTable *param))
{
	SET_FUNCPTR(client->on_create_plugin_widget);
	g_signal_connect(client->view, "create-plugin-widget", G_CALLBACK(_surfi_client_set_callback_create_plugin_widget), client);
}
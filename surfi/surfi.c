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
	return (client->on_close_web_view)(client);
}

void surfi_client_set_callback_close_web_view(SurfiClient *client, bool(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_close_web_view);
	g_signal_connect(client->view, "close-web-view", G_CALLBACK(_surfi_client_set_callback_close_web_view), client);
}

bool _surfi_client_set_callback_console_message(WebKitWebView *view, char *message, int line, char *source_id, SurfiClient *client)
{
	return (client->on_console_message)(client, message, line, source_id);
}

void surfi_client_set_callback_console_message(SurfiClient *client, bool(*callback)(SurfiClient *client, char *message, int line, char *source_id))
{
	SET_FUNCPTR(client->on_console_message);
	g_signal_connect(client->view, "console-message", G_CALLBACK(_surfi_client_set_callback_console_message), client);
}

bool _surfi_client_set_callback_context_menu(WebKitWebView *view, GtkWidget *default_menu, WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard, SurfiClient *client)
{
	return (client->on_context_menu)(client, default_menu, hit_test_result, triggered_with_keyboard);
}

void surfi_client_set_callback_context_menu(SurfiClient *client, bool(*callback)(SurfiClient *client,
		GtkWidget *default_menu, WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard))
{
	SET_FUNCPTR(client->on_context_menu);
	g_signal_connect(client->view, "context-menu", G_CALLBACK(_surfi_client_set_callback_context_menu), client);
}

void _surfi_client_set_callback_copy_clipboard(WebKitWebView *view, SurfiClient *client)
{
	(client->on_copy_clipboard)(client);
}

void surfi_client_set_callback_copy_clipboard(SurfiClient *client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_copy_clipboard);
	g_signal_connect(client->view, "copy-clipboard", G_CALLBACK(_surfi_client_set_callback_copy_clipboard), client);
}

void _surfi_client_set_callback_create_plugin_widget(WebKitWebView *view, char *mime_type, char *uri, GHashTable *param, SurfiClient *client)
{
	(client->on_create_plugin_widget)(client, mime_type, uri, param);
}

void surfi_client_set_callback_create_plugin_widget(SurfiClient *client, void(*callback)(SurfiClient *client, char *mime_type, char *uri, GHashTable *param))
{
	SET_FUNCPTR(client->on_create_plugin_widget);
	g_signal_connect(client->view, "create-plugin-widget", G_CALLBACK(_surfi_client_set_callback_create_plugin_widget), client);
}

void _surfi_client_set_callback_create_webview(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_create_webview)(client, frame);
}

void surfi_client_set_callback_create_webview(SurfiClient *client, void(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_create_webview);
	g_signal_connect(client->view, "create-web-view", G_CALLBACK(_surfi_client_set_callback_create_webview), client);
}

void _surfi_client_set_callback_cut_clipboard(WebKitWebView *view, SurfiClient *client)
{
	(client->on_cut_clipboard)(client);
}

void surfi_client_set_callback_cut_clipboard(SurfiClient *client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_cut_clipboard);
	g_signal_connect(client->view, "cut-clipboard", G_CALLBACK(_surfi_client_set_callback_cut_clipboard), client);
}

void _surfi_client_set_callback_database_quota_exceeded(WebKitWebView *view, GObject *frame, GObject *database, SurfiClient *client)
{
	(client->on_database_quota_exceeded)(client, frame, database);
}

void surfi_client_set_callback_database_quota_exceeded(SurfiClient *client, void(*callback)(SurfiClient *client, GObject *frame, GObject *database))
{
	SET_FUNCPTR(client->on_database_quota_exceeded);
	g_signal_connect(client->view, "database-quota-exceeded", G_CALLBACK(_surfi_client_set_callback_database_quota_exceeded), client);
}

void _surfi_client_set_callback_document_load_finished(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_document_load_finished)(client, frame);
}

void surfi_client_set_callback_document_load_finished(SurfiClient *client, void(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_document_load_finished);
	g_signal_connect(client->view, "document-load-finished", G_CALLBACK(_surfi_client_set_callback_document_load_finished), client);
}

void _surfi_client_set_callback_download_requested(WebKitWebView *webview, GObject *download, SurfiClient *client)
{
	(client->on_download_requested)(client, download);
}

void surfi_client_set_callback_download_requested(SurfiClient *client, void(*callback)(SurfiClient *client,GObject *download))
{
	SET_FUNCPTR(client->on_download_requested);
	g_signal_connect(client->view, "download-requested", G_CALLBACK(_surfi_client_set_callback_download_requested), client);
}

void _surfi_client_set_callback_editing_began(WebKitWebView *view, SurfiClient *client)
{
	(client->on_editing_began)(client);
}

void surfi_client_set_callback_editing_began(SurfiClient *client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_editing_began);
	g_signal_connect(client->view, "editing-began", G_CALLBACK(_surfi_client_set_callback_editing_began), client);
}

void _surfi_client_set_callback_editing_ended(WebKitWebView *view, SurfiClient *client)
{
	(client->on_editing_ended)(client);
}

void surfi_client_set_callback_editing_ended(SurfiClient *client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_editing_ended);
	g_signal_connect(client->view, "editing-ended", G_CALLBACK(_surfi_client_set_callback_editing_ended), client);
}

bool _surfi_client_set_callback_entering_fullscreen(WebKitWebView *view, WebKitDOMHTMLElement *element, SurfiClient *client)
{
	return (client->on_entering_fullscreen)(client, element);
}

void surfi_client_set_callback_entering_fullscreen(SurfiClient *client, bool(*callback)(SurfiClient *client, WebKitDOMHTMLElement *element))
{
	SET_FUNCPTR(client->on_entering_fullscreen);
	g_signal_connect(client->view, "entering-fullscreen", G_CALLBACK(_surfi_client_set_callback_entering_fullscreen), client);
}


void _surfi_client_set_callback_frame_created(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_frame_created)(client, frame);
}

void surfi_client_set_callback_frame_created(SurfiClient *client, void(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_frame_created);
	g_signal_connect(client->view, "frame-created", G_CALLBACK(_surfi_client_set_callback_frame_created), client);
}

void _surfi_client_set_callback_geolocation_policy_decision_cancelled(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_geolocation_policy_decision_cancelled)(client, frame);
}

void surfi_client_set_callback_geolocation_policy_decision_cancelled(SurfiClient *client, void(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_geolocation_policy_decision_cancelled);
	g_signal_connect(client->view, "geolocation-policy-decision-cancelled", G_CALLBACK(_surfi_client_set_callback_geolocation_policy_decision_cancelled), client);
}

bool _surfi_client_set_callback_geolocation_policy_decision_requested(WebKitWebView *view, WebKitWebFrame *frame, WebKitGeolocationPolicyDecision *policy_decision, SurfiClient *client)
{
	return (client->on_geolocation_policy_decision_requested)(client, frame, policy_decision);
}

void surfi_client_set_callback_geolocation_policy_decision_requested(SurfiClient *client, bool(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitGeolocationPolicyDecision *policy_decision))
{
	SET_FUNCPTR(client->on_geolocation_policy_decision_requested);
	g_signal_connect(client->view, "geolocation-policy-decision-requested", G_CALLBACK(_surfi_client_set_callback_geolocation_policy_decision_requested), client);
}

void _surfi_client_set_callback_hovering_over_link(WebKitWebView *view, char *title, char *uri, SurfiClient *client)
{
	(client->on_hovering_over_link)(client, title, uri);
}

void surfi_client_set_callback_hovering_over_link(SurfiClient *client, void(*callback)(SurfiClient *client, char *title, char *uri))
{
	SET_FUNCPTR(client->on_hovering_over_link);
	g_signal_connect(client->view, "hovering-over-link", G_CALLBACK(_surfi_client_set_callback_hovering_over_link), client);
}

void _surfi_client_set_callback_icon_loaded(WebKitWebView *view, char *icon_uri, SurfiClient *client)
{
	(client->on_icon_loaded)(client, icon_uri);
}

void surfi_client_set_callback_icon_loaded(SurfiClient *client, void(*callback)(SurfiClient *client, char *icon_uri))
{
	SET_FUNCPTR(client->on_icon_loaded);
	g_signal_connect(client->view, "icon-loaded", G_CALLBACK(_surfi_client_set_callback_icon_loaded), client);
}

bool _surfi_client_set_callback_leaving_fullscreen(WebKitWebView *view, WebKitDOMHTMLElement *element, SurfiClient *client)
{
	return (client->on_leaving_fullscreen)(client, element);
}

void surfi_client_set_callback_leaving_fullscreen(SurfiClient *client, bool(*callback)(SurfiClient *client, WebKitDOMHTMLElement *element))
{
	SET_FUNCPTR(client->on_leaving_fullscreen);
	g_signal_connect(client->view, "leaving-fullscreen", G_CALLBACK(_surfi_client_set_callback_leaving_fullscreen), client);
}

void _surfi_client_set_callback_load_commited(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_load_commited)(client, frame);
}

void surfi_client_set_callback_load_commited(SurfiClient *client, void (*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_load_commited);
	g_signal_connect(client->view, "load-commited", G_CALLBACK(_surfi_client_set_callback_load_commited), client);
}

bool _surfi_client_set_callback_load_error(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	return (client->on_load_error)(client, frame);
}

void surfi_client_set_callback_load_error(SurfiClient *client, bool(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_load_error);
	g_signal_connect(client->view, "load-error", G_CALLBACK(_surfi_client_set_callback_load_error), client);
}

void _surfi_client_set_callback_load_finished(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_load_finished)(client, frame);
}

void surfi_client_set_callback_load_finished(SurfiClient *client, void(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_load_finished);
	g_signal_connect(client->view, "load-finished", G_CALLBACK(_surfi_client_set_callback_load_finished), client);
}

void _surfi_client_set_callback_load_progress_changed(WebKitWebView *view, int progress, SurfiClient *client)
{
	(client->on_load_progress_changed)(client, progress);
}

void surfi_client_set_callback_load_progress_changed(SurfiClient *client, void(*callback)(SurfiClient *client, int progress))
{
	SET_FUNCPTR(client->on_load_progress_changed);
	g_signal_connect(client->view, "load-progress-changed", G_CALLBACK(_surfi_client_set_callback_load_progress_changed), client);
}

void _surfi_client_set_callback_load_started(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_load_started)(client, frame);
}

void surfi_client_set_callback_load_started(SurfiClient *client, void (*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_load_started);
	g_signal_connect(client->view, "load-started", G_CALLBACK(_surfi_client_set_callback_load_started), client);
}

bool _surfi_client_set_callback_mime_type_policy_decision_requested(WebKitWebView *view, WebKitWebFrame *frame,
	WebKitNetworkRequest *request, char *mimetype, WebKitWebPolicyDecision *policy_decision, SurfiClient *client)
{
	return (client->on_mime_type_policy_decision_requested)(client, frame, request, mimetype, policy_decision);
}

void surfi_client_set_callback_mime_type_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitNetworkRequest *request,
	                char *mimetype, WebKitWebPolicyDecision *policy_decision))
{
	SET_FUNCPTR(client->on_mime_type_policy_decision_requested);
	g_signal_connect(client->view, "mime-type-policy-decision-requested", G_CALLBACK(_surfi_client_set_callback_mime_type_policy_decision_requested), client);
}

bool _surfi_client_set_callback_move_cursor(WebKitWebView *view, GtkMovementStep step, int count, SurfiClient *client)
{
	return (client->on_move_cursor)(client, step, count);
}

void surfi_client_set_callback_move_cursor(SurfiClient *client, bool(*callback)(SurfiClient *client, GtkMovementStep step, int count))
{
	SET_FUNCPTR(client->on_move_cursor);
	g_signal_connect(client->view, "move-cursor", G_CALLBACK(_surfi_client_set_callback_move_cursor), client);
}

bool _surfi_client_set_callback_navigation_policy_decision_requested(WebKitWebView *view, WebKitWebFrame *frame,
	WebKitNetworkRequest *request, WebKitWebNavigationAction *navigation_action, WebKitWebPolicyDecision *policy_decision, SurfiClient *client)
{
	return (client->on_navigation_policy_decision_requested)(client, frame, request, navigation_action, policy_decision);
}

void surfi_client_set_callback_navigation_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client,  WebKitWebFrame *frame, WebKitNetworkRequest *request,
	                WebKitWebNavigationAction *navigation_action, WebKitWebPolicyDecision *policy_decision))
{
	SET_FUNCPTR(client->on_navigation_policy_decision_requested);
	g_signal_connect(client->view, "navigation-policy-decision-requested", G_CALLBACK(_surfi_client_set_callback_navigation_policy_decision_requested), client);
}

WebKitNavigationResponse _surfi_client_set_callback_navigation_requested(WebKitWebView *view, WebKitWebFrame *frame, WebKitNetworkRequest *request, SurfiClient *client)
{
	return (client->on_navigation_requested)(client, frame, request);
}

void surfi_client_set_callback_navigation_requested(SurfiClient *client, WebKitNavigationResponse(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitNetworkRequest *request))
{
	SET_FUNCPTR(client->on_navigation_requested);
	g_signal_connect(client->view, "navigation-requested", G_CALLBACK(_surfi_client_set_callback_navigation_requested), client);
}

bool _surfi_client_set_callback_new_window_policy_decision_requested(WebKitWebView *view, WebKitWebFrame *frame,
	WebKitNetworkRequest *request, WebKitWebNavigationAction *navigation_action, WebKitWebPolicyDecision *policy_decision, SurfiClient *client)
{
	return (client->on_new_window_policy_decision_requested)(client, frame, request, navigation_action, policy_decision);
}

void surfi_client_set_callback_new_window_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitNetworkRequest *request,
	                WebKitWebNavigationAction *navigation_action, WebKitWebPolicyDecision *policy_decision))
{
	SET_FUNCPTR(client->on_new_window_policy_decision_requested);
	g_signal_connect(client->view, "new-window-policy-decision-requested", G_CALLBACK(_surfi_client_set_callback_new_window_policy_decision_requested), client);
}

void _surfi_client_set_callback_onload_event(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	(client->on_onload_event)(client, frame);
}

void surfi_client_set_callback_onload_event(SurfiClient *client, void(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_onload_event);
	g_signal_connect(client->view, "onload-event", G_CALLBACK(_surfi_client_set_callback_onload_event), client);
}

void _surfi_client_set_callback_paste_clipboard(WebKitWebView *view, SurfiClient *client)
{
	(client->on_paste_clipboard)(client);
}

void surfi_client_set_callback_paste_clipboard(SurfiClient *client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_paste_clipboard);
	g_signal_connect(client->view, "paste-clipboard", G_CALLBACK(_surfi_client_set_callback_paste_clipboard), client);
}

void _surfi_client_set_callback_populate_popup(WebKitWebView *view, GtkMenu *menu, SurfiClient *client)
{
	(client->on_populate_popup)(client, menu);
}

void surfi_client_set_callback_populate_popup(SurfiClient *client, void(*callback)(SurfiClient *client, GtkMenu *menu))
{
	SET_FUNCPTR(client->on_populate_popup);
	g_signal_connect(client->view, "populate-popup", G_CALLBACK(_surfi_client_set_callback_populate_popup), client);
}

bool _surfi_client_set_callback_print_requested(WebKitWebView *view, WebKitWebFrame *frame, SurfiClient *client)
{
	return (client->on_print_requested)(client, frame);
}

void surfi_client_set_callback_print_requested(SurfiClient *client, bool(*callback)(SurfiClient *client, WebKitWebFrame *frame))
{
	SET_FUNCPTR(client->on_print_requested);
	g_signal_connect(client->view, "print-requested", G_CALLBACK(_surfi_client_set_callback_print_requested), client);
}

void _surfi_client_set_callback_redo(WebKitWebView *view, SurfiClient *client)
{
	(client->on_redo)(client);
}

void surfi_client_set_callback_redo(SurfiClient *client, void(*callback)(SurfiClient *client))
{
	SET_FUNCPTR(client->on_redo);
	g_signal_connect(client->view, "redo", G_CALLBACK(_surfi_client_set_callback_redo), client);
}

void _surfi_client_set_callback_resource_content_length_received(WebKitWebView *view, WebKitWebFrame *frame, WebKitWebResource *resource, int length, SurfiClient *client)
{
	(client->on_resource_content_length_received)(client, frame, resource, length);
}

void surfi_client_set_callback_resource_content_length_received(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitWebResource *resource, int length))
{
	SET_FUNCPTR(client->on_resource_content_length_received);
	g_signal_connect(client->view, "resource-content-length-received", G_CALLBACK(_surfi_client_set_callback_resource_content_length_received), client);
}
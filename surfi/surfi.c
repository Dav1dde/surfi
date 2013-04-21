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
	SurfiClient *client;

	if(!(client = calloc(1, sizeof(SurfiClient)))) {
		error("Malloc failed");
		return NULL;
	}

	client->window = gtk_offscreen_window_new();
	client->view = webkit_web_view_new();
	gtk_widget_set_size_request(client->view, width, height);
	gtk_container_add (GTK_CONTAINER(client->window), client->view);
	gtk_widget_show_all(client->window);

	return client;
}

void surfi_client_free(SurfiClient *client)
{
	gtk_widget_destroy(client->view);
	gtk_widget_destroy(client->window);
	free(client);
}

void surfi_client_set_size(SurfiClient *client, int width, int height)
{
	gtk_widget_set_size_request(client->view, width, height);
}


void surfi_client_set_userptr(SurfiClient *client, void *ptr)
{
	client->userptr = ptr;
}

void* surfi_client_get_userptr(SurfiClient *client)
{
	return client->userptr;
}

Pixbuf* surfi_client_get_pixbuf(SurfiClient* client)
{
	return gtk_offscreen_window_get_pixbuf(GTK_OFFSCREEN_WINDOW(client->window));
}

bool surfi_client_can_copy_clipboard(SurfiClient *client)
{
	return webkit_web_view_can_copy_clipboard(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_can_cut_clipboard(SurfiClient *client)
{
	return webkit_web_view_can_cut_clipboard(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_can_go_back(SurfiClient *client)
{
	return webkit_web_view_can_go_back(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_can_go_back_or_forward(SurfiClient *client, int steps)
{
	return webkit_web_view_can_go_back_or_forward(WEBKIT_WEB_VIEW(client->view), steps);
}

bool surfi_client_can_go_forward(SurfiClient *client)
{
	return webkit_web_view_can_go_forward(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_can_paste_clipboard(SurfiClient *client)
{
	return webkit_web_view_can_paste_clipboard(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_can_redo(SurfiClient *client)
{
	return webkit_web_view_can_redo(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_can_show_mime_type(SurfiClient *client, const char *mime_type)
{
	return webkit_web_view_can_show_mime_type(WEBKIT_WEB_VIEW(client->view), mime_type);
}

bool surfi_client_can_undo(SurfiClient *client)
{
	return webkit_web_view_can_undo(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_copy_clipboard(SurfiClient *client)
{
	return webkit_web_view_copy_clipboard(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_cut_clipboard(SurfiClient *client)
{
	return webkit_web_view_cut_clipboard(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_delete_selection(SurfiClient *client)
{
	return webkit_web_view_delete_selection(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_execute_script(SurfiClient *client, const char *script)
{
	return webkit_web_view_execute_script(WEBKIT_WEB_VIEW(client->view), script);
}

WebKitWebBackForwardList* surfi_client_get_back_forward_list(SurfiClient *client)
{
	return webkit_web_view_get_back_forward_list(WEBKIT_WEB_VIEW(client->view));
}

GtkTargetList* surfi_client_get_copy_target_list(SurfiClient *client)
{
	return webkit_web_view_get_copy_target_list(WEBKIT_WEB_VIEW(client->view));
}

const char* surfi_client_get_custom_encoding(SurfiClient *client)
{
	return webkit_web_view_get_custom_encoding(WEBKIT_WEB_VIEW(client->view));
}

WebKitDOMDocument* surfi_client_get_dom_document(SurfiClient *client)
{
	return webkit_web_view_get_dom_document(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_get_editable(SurfiClient *client)
{
	return webkit_web_view_get_editable(WEBKIT_WEB_VIEW(client->view));
}

const char* surfi_client_get_encoding(SurfiClient *client)
{
	return webkit_web_view_get_encoding(WEBKIT_WEB_VIEW(client->view));
}

WebKitWebFrame* surfi_client_get_focused_frame(SurfiClient *client)
{
	return webkit_web_view_get_focused_frame(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_get_full_content_zoom(SurfiClient *client)
{
	return webkit_web_view_get_full_content_zoom(WEBKIT_WEB_VIEW(client->view));
}

WebKitHitTestResult* surfi_client_get_hit_test_result(SurfiClient *client, GdkEventButton *event)
{
	return webkit_web_view_get_hit_test_result(WEBKIT_WEB_VIEW(client->view), event);
}

Pixbuf* surfi_client_get_icon_pixbuf(SurfiClient *client)
{
	return webkit_web_view_get_icon_pixbuf(WEBKIT_WEB_VIEW(client->view));
}

const char* surfi_client_get_icon_uri(SurfiClient *client)
{
	return webkit_web_view_get_icon_uri(WEBKIT_WEB_VIEW(client->view));
}

WebKitWebInspector* surfi_client_get_inspector(SurfiClient *client)
{
	return webkit_web_view_get_inspector(WEBKIT_WEB_VIEW(client->view));
}

WebKitLoadStatus surfi_client_get_load_status(SurfiClient *client)
{
	return webkit_web_view_get_load_status(WEBKIT_WEB_VIEW(client->view));
}

WebKitWebFrame* surfi_client_get_main_frame(SurfiClient *client)
{
	return webkit_web_view_get_main_frame(WEBKIT_WEB_VIEW(client->view));
}

GtkTargetList* surfi_client_get_paste_target_list(SurfiClient *client)
{
	return webkit_web_view_get_paste_target_list(WEBKIT_WEB_VIEW(client->view));
}

double surfi_client_get_progress(SurfiClient *client)
{
	return webkit_web_view_get_progress(WEBKIT_WEB_VIEW(client->view));
}

WebKitWebSettings* surfi_client_get_settings(SurfiClient *client)
{
	return webkit_web_view_get_settings(WEBKIT_WEB_VIEW(client->view));
}

const char* surfi_client_get_title(SurfiClient *client)
{
	return webkit_web_view_get_title(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_get_transparent(SurfiClient *client)
{
	return webkit_web_view_get_transparent(WEBKIT_WEB_VIEW(client->view));
}

const char* surfi_client_get_uri(SurfiClient *client)
{
	return webkit_web_view_get_uri(WEBKIT_WEB_VIEW(client->view));
}

WebKitWebViewViewMode surfi_client_get_view_mode(SurfiClient *client)
{
	return webkit_web_view_get_view_mode(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_get_view_source_mode(SurfiClient *client)
{
	return webkit_web_view_get_view_source_mode(WEBKIT_WEB_VIEW(client->view));
}

WebKitViewportAttributes* surfi_client_get_viewport_attributes(SurfiClient *client)
{
	return webkit_web_view_get_viewport_attributes(WEBKIT_WEB_VIEW(client->view));
}

float surfi_client_get_zoom_level(SurfiClient *client)
{
	return webkit_web_view_get_zoom_level(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_go_back(SurfiClient *client)
{
	return webkit_web_view_go_back(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_go_back_or_forward(SurfiClient *client, int steps)
{
	return webkit_web_view_go_back_or_forward(WEBKIT_WEB_VIEW(client->view), steps);
}

void surfi_client_go_forward(SurfiClient *client)
{
	return webkit_web_view_go_forward(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_go_to_back_forward_item(SurfiClient *client, WebKitWebHistoryItem *item)
{
	return webkit_web_view_go_to_back_forward_item(WEBKIT_WEB_VIEW(client->view), item);
}

bool surfi_client_has_selection(SurfiClient *client)
{
	return webkit_web_view_has_selection(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_load_html_string(SurfiClient *client, const char* content, const char* base_uri)
{
	return webkit_web_view_load_html_string(WEBKIT_WEB_VIEW(client->view), content, base_uri);
}

void surfi_client_load_request(SurfiClient *client, WebKitNetworkRequest *request)
{
	return webkit_web_view_load_request(WEBKIT_WEB_VIEW(client->view), request);
}

void surfi_client_load_string(SurfiClient *client, const char *content, const char *mime_type, const char *encoding, const char *base_uri)
{
	return webkit_web_view_load_string(WEBKIT_WEB_VIEW(client->view), content, mime_type, encoding, base_uri);
}

void surfi_client_load_uri(SurfiClient *client, const char *uri)
{
	return webkit_web_view_load_uri(WEBKIT_WEB_VIEW(client->view), uri);
}

unsigned int surfi_client_mark_text_matches(SurfiClient *client, const char *string, bool case_sensitive, unsigned int limit)
{
	return webkit_web_view_mark_text_matches(WEBKIT_WEB_VIEW(client->view), string, case_sensitive, limit);
}

void surfi_client_move_cursor(SurfiClient *client, GtkMovementStep step, int count)
{
	return webkit_web_view_move_cursor(WEBKIT_WEB_VIEW(client->view), step, count);
}

void surfi_client_paste_clipboard(SurfiClient *client)
{
	return webkit_web_view_paste_clipboard(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_redo(SurfiClient *client)
{
	return webkit_web_view_redo(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_reload(SurfiClient *client)
{
	return webkit_web_view_reload(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_reload_bypass_cache(SurfiClient *client)
{
	return webkit_web_view_reload_bypass_cache(WEBKIT_WEB_VIEW(client->view));
}

bool surfi_client_search_text(SurfiClient *client, const char *text, bool case_sensitive, bool forward, bool wrap)
{
	return webkit_web_view_search_text(WEBKIT_WEB_VIEW(client->view), text, case_sensitive, forward, wrap);
}

void surfi_client_select_all(SurfiClient *client)
{
	return webkit_web_view_select_all(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_set_custom_encoding(SurfiClient *client, const char *encoding)
{
	return webkit_web_view_set_custom_encoding(WEBKIT_WEB_VIEW(client->view), encoding);
}

void surfi_client_set_editable(SurfiClient *client, bool flag)
{
	return webkit_web_view_set_editable(WEBKIT_WEB_VIEW(client->view), flag);
}

void surfi_client_set_full_content_zoom(SurfiClient *client, bool full_content_zoom)
{
	return webkit_web_view_set_full_content_zoom(WEBKIT_WEB_VIEW(client->view), full_content_zoom);
}

void surfi_client_set_highlight_text_matches(SurfiClient *client, bool highlight)
{
	return webkit_web_view_set_highlight_text_matches(WEBKIT_WEB_VIEW(client->view), highlight);
}

void surfi_client_set_maintains_back_forward_list(SurfiClient *client, bool flag)
{
	return webkit_web_view_set_maintains_back_forward_list(WEBKIT_WEB_VIEW(client->view), flag);
}

void surfi_client_set_settings(SurfiClient *client, WebKitWebSettings *settings)
{
	return webkit_web_view_set_settings(WEBKIT_WEB_VIEW(client->view), settings);
}

void surfi_client_set_transparent(SurfiClient *client, bool flag)
{
	return webkit_web_view_set_transparent(WEBKIT_WEB_VIEW(client->view), flag);
}

void surfi_client_set_view_mode(SurfiClient *client, WebKitWebViewViewMode mode)
{
	return webkit_web_view_set_view_mode(WEBKIT_WEB_VIEW(client->view), mode);
}

void surfi_client_set_view_source_mode(SurfiClient *client, bool view_source_mode)
{
	return webkit_web_view_set_view_source_mode(WEBKIT_WEB_VIEW(client->view), view_source_mode);
}

void surfi_client_set_zoom_level(SurfiClient *client, float zoom_level)
{
	return webkit_web_view_set_zoom_level(WEBKIT_WEB_VIEW(client->view), zoom_level);
}

void surfi_client_stop_loading(SurfiClient *client)
{
	return webkit_web_view_stop_loading(WEBKIT_WEB_VIEW(client->view));
}

Pixbuf* surfi_client_try_get_favicon_pixbuf(SurfiClient *client, int width, int height)
{
	return webkit_web_view_try_get_favicon_pixbuf(WEBKIT_WEB_VIEW(client->view), width, height	);
}

void surfi_client_undo(SurfiClient *client)
{
	return webkit_web_view_undo(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_unmark_text_matches(SurfiClient *client)
{
	return webkit_web_view_unmark_text_matches(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_zoom_in(SurfiClient *client)
{
	return webkit_web_view_zoom_in(WEBKIT_WEB_VIEW(client->view));
}

void surfi_client_zoom_out(SurfiClient *client)
{
	return webkit_web_view_zoom_out(WEBKIT_WEB_VIEW(client->view));
}

WebKitWebWindowFeatures* surfi_client_get_window_features(SurfiClient *client)
{
	return webkit_web_view_get_window_features(WEBKIT_WEB_VIEW(client->view));
}

void* surfi_client_get_snapshot(SurfiClient *client)
{
	return webkit_web_view_get_snapshot(WEBKIT_WEB_VIEW(client->view));
}
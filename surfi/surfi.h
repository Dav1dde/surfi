/* See LICENSE file for copyright and license details. */

#include "surfi/pixbuf.h"

/*
 * Represents the Surfi Client, holding all relevant
 * information, you should not access the members.
 *
 */
typedef struct SurfiClient {
	GtkWidget *window; // Offscreen window
	GtkWidget *view; // The webkit widget
	GtkWidget *scroll;

	void *userptr; // custom user pointer passed to all callbacks

	bool (*on_close_web_view)(struct SurfiClient *client);
	bool (*on_console_message)(struct SurfiClient *client, char *message, int line, char *source_id);
	bool (*on_context_menu)(struct SurfiClient *client, GtkWidget *default_menu,
	                        WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard);
	void (*on_copy_clipboard)(struct SurfiClient *client);
	void (*on_create_plugin_widget)(struct SurfiClient *client, char *mime_type, char *uri, GHashTable *param);
	void (*on_create_webview)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_cut_clipboard)(struct SurfiClient *client);
	void (*on_database_quota_exceeded)(struct SurfiClient *client, GObject *frame, GObject *database);
	void (*on_document_load_finished)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_download_requested)(struct SurfiClient *client, GObject *download);
	void (*on_editing_began)(struct SurfiClient *client);
	void (*on_editing_ended)(struct SurfiClient *client);
	bool (*on_entering_fullscreen)(struct SurfiClient *client, WebKitDOMHTMLElement *element);
	void (*on_frame_created)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_geolocation_policy_decision_cancelled)(struct SurfiClient *client, WebKitWebFrame *frame);
	bool (*on_geolocation_policy_decision_requested)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                                 WebKitGeolocationPolicyDecision *policy_decision);
	void (*on_hovering_over_link)(struct SurfiClient *client, char *title, char *uri);
	void (*on_icon_loaded)(struct SurfiClient *client, char *icon_uri);
	bool (*on_leaving_fullscreen)(struct SurfiClient *client, WebKitDOMHTMLElement *element);
	void (*on_load_commited)(struct SurfiClient *client, WebKitWebFrame *frame);
	bool (*on_load_error)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_load_finished)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_load_progress_changed)(struct SurfiClient *client, int progress);
	void (*on_load_started)(struct SurfiClient *client, WebKitWebFrame *frame);
	bool (*on_mime_type_policy_decision_requested)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                               WebKitNetworkRequest *request, char *mimetype,
	                                               WebKitWebPolicyDecision *policy_decision);
	bool (*on_move_cursor)(struct SurfiClient *client, GtkMovementStep step, int count);
	bool (*on_navigation_policy_decision_requested)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                                WebKitNetworkRequest *request,
	                                                WebKitWebNavigationAction *navigation_action,
	                                                WebKitWebPolicyDecision *policy_decision);
	WebKitNavigationResponse (*on_navigation_requested)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                                    WebKitNetworkRequest *request);
	bool (*on_new_window_policy_decision_requested)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                                WebKitNetworkRequest *request,
	                                                WebKitWebNavigationAction *navigation_action,
	                                                WebKitWebPolicyDecision *policy_decision);
	void (*on_onload_event)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_paste_clipboard)(struct SurfiClient *client);
	void (*on_populate_popup)(struct SurfiClient *client, GtkMenu *menu);
	bool (*on_print_requested)(struct SurfiClient *client, WebKitWebFrame *frame);
	void (*on_redo)(struct SurfiClient *client);
	void (*on_resource_content_length_received)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                            WebKitWebResource *resource, int length_received);
	void (*on_resource_load_failed)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                WebKitWebResource *resource, GError *error);
	void (*on_resource_load_finished)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                  WebKitWebResource *resource);
	void (*on_resource_request_starting)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                     WebKitWebResource *resource, WebKitNetworkRequest *request,
	                                     WebKitNetworkResponse *response);
	void (*on_resource_response_received)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                      WebKitWebResource *resource, WebKitNetworkResponse *response);
	bool (*on_run_file_chooser)(struct SurfiClient *client, WebKitFileChooserRequest *request);
	bool (*on_script_alert)(struct SurfiClient *client, WebKitWebFrame *frame, char *message);
	bool (*on_script_confirm)(struct SurfiClient *client, WebKitWebFrame *frame, char *message, void *confirmed);
	bool (*on_script_prmpt)(struct SurfiClient *client, WebKitWebFrame *frame, char *message, char *default_, void *text);
	void (*on_select_all)(struct SurfiClient *client);
	void (*on_selection_changed)(struct SurfiClient *client);
	bool (*on_should_apply_style)(struct SurfiClient *client, WebKitDOMCSSStyleDeclaration *arg1, WebKitDOMRange *arg2);
	bool (*on_should_begin_editing)(struct SurfiClient *client, WebKitDOMRange *arg1);
	bool (*on_should_change_selected_range)(struct SurfiClient *client, WebKitDOMRange *arg1, WebKitDOMRange *arg2,
	                                        WebKitSelectionAffinity arg3, bool arg4);
	bool (*on_should_delete_range)(struct SurfiClient *client, WebKitDOMRange *arg1);
	bool (*on_should_end_editing)(struct SurfiClient *client, WebKitDOMRange *arg1);
	bool (*on_should_insert_node)(struct SurfiClient *client, WebKitDOMNode *arg1, WebKitDOMRange *arg2,
	                              WebKitInsertAction *arg3);
	bool (*on_should_insert_text)(struct SurfiClient *client, char *arg1, WebKitDOMRange *arg2,
								  WebKitInsertAction *arg3);
	bool (*on_should_show_delete_interface_for_element)(struct SurfiClient *client, WebKitDOMHTMLElement *arg1);
	void (*on_status_bar_text_changed)(struct SurfiClient *client, char *arg1);
	void (*on_title_changed)(struct SurfiClient *client, WebKitWebFrame *frame, char *title);
	void (*on_undo)(struct SurfiClient *client);
	void (*on_user_changed_contents)(struct SurfiClient *client);
	void (*on_viewport_attributes_changed)(struct SurfiClient *client, WebKitViewportAttributes *arg1);
	void (*on_viewport_attributes_recompute_requested)(struct SurfiClient *client, WebKitViewportAttributes *arg1);
	void (*on_webview_ready)(struct SurfiClient *client);
	void (*on_window_object_cleared)(struct SurfiClient *client, WebKitWebFrame *frame,
	                                 void *context, void *window_object);
} SurfiClient;


// abcdefghijklmnopqrstuvqxyz

// TODO
static void error(const char *errstr, ...);

/*
 * Initializes surfi.
 * This is basically a call to gtk_init_check.
 *
 * RETURNS: true if call was succesful otherwise false
 *
 */
bool surfi_init(void);

/*
 * This updates everything related to surfi *and* gtk.
 * You can omit a call to surfi_poll if you're running
 * the gtk mainloop your own.
 *
 * RETURNS: true if there were events which needed processing, otherwise false
 */
bool surfi_poll(void);

/*
 * Initializes a new SurfiClient representing the offscreen webview.
 *
 * RETURNS: SurfiClient*
 */
SurfiClient* surfi_client_new(int width, int height);

/*
 * Destroys a SurfiClient and frees the allocated memory.
 * To avoid memory leaks this function has to be called!
 *
 */
void surfi_client_free(SurfiClient *client);

/*
 * Sets the size of the offscreen webview.
 *
 */
void surfi_client_set_size(SurfiClient *client, int width, int height);

/*
 * Set a userptr for a SurfiClient.
 *
 */
void surfi_client_set_userptr(SurfiClient *client, void *ptr);

/*
 * Gets the userptr from a SurfiClient.
 *
 */
void* surfi_client_get_userptr(SurfiClient *client);

/*
 * Retrieves a snapshot of the currently rendered page
 *
 */
Pixbuf* surfi_client_get_pixbuf(SurfiClient *client);


// http://webkitgtk.org/reference/webkitgtk/stable/webkitgtk-webkitwebview.html
bool surfi_client_can_copy_clipboard(SurfiClient *client);
bool surfi_client_can_cut_clipboard(SurfiClient *client);
bool surfi_client_can_go_back(SurfiClient *client);
bool surfi_client_can_go_back_or_forward(SurfiClient *client, int steps);
bool surfi_client_can_go_forward(SurfiClient *client);
bool surfi_client_can_paste_clipboard(SurfiClient *client);
bool surfi_client_can_redo(SurfiClient *client);
bool surfi_client_can_show_mime_type(SurfiClient *client, const char *mime_type);
bool surfi_client_can_undo(SurfiClient *client);
void surfi_client_copy_clipboard(SurfiClient *client);
void surfi_client_cut_clipboard(SurfiClient *client);
void surfi_client_delete_selection(SurfiClient *client);
void surfi_client_execute_script(SurfiClient *client, const char *script);
WebKitWebBackForwardList* surfi_client_get_back_forward_list(SurfiClient *client);
GtkTargetList* surfi_client_get_copy_target_list(SurfiClient *client);
const char* surfi_client_get_custom_encoding(SurfiClient *client);
WebKitDOMDocument* surfi_client_get_dom_document(SurfiClient *client);
bool surfi_client_get_editable(SurfiClient *client);
const char* surfi_client_get_encoding(SurfiClient *client);
WebKitWebFrame* surfi_client_get_focused_frame(SurfiClient *client);
bool surfi_client_get_full_content_zoom(SurfiClient *client);
WebKitHitTestResult* surfi_client_get_hit_test_result(SurfiClient *client, GdkEventButton *event);
Pixbuf* surfi_client_get_icon_pixbuf(SurfiClient *client);
const char* surfi_client_get_icon_uri(SurfiClient *client);
WebKitWebInspector* surfi_client_get_inspector(SurfiClient *client);
WebKitLoadStatus surfi_client_get_load_status(SurfiClient *client);
WebKitWebFrame* surfi_client_get_main_frame(SurfiClient *client);
GtkTargetList* surfi_client_get_paste_target_list(SurfiClient *client);
double surfi_client_get_progress(SurfiClient *client);
WebKitWebSettings* surfi_client_get_settings(SurfiClient *client);
const char* surfi_client_get_title(SurfiClient *client);
bool surfi_client_get_transparent(SurfiClient *client);
const char* surfi_client_get_uri(SurfiClient *client);
WebKitWebViewViewMode surfi_client_get_view_mode(SurfiClient *client);
bool surfi_client_get_view_source_mode(SurfiClient *client);
WebKitViewportAttributes* surfi_get_viewport_attributes(SurfiClient *client);
float surfi_get_zoom_level(SurfiClient *client);
void surfi_client_go_back(SurfiClient *client);
void surfi_client_go_back_or_forward(SurfiClient *client, int steps);
void surfi_client_go_forward(SurfiClient *client);
bool surfi_client_go_to_back_forward_item(SurfiClient *client, WebKitWebHistoryItem *item);
bool surfi_client_has_selection(SurfiClient *client);
void surfi_client_load_html_string(SurfiClient *client, const char* content, const char* base_uri);
void surfi_client_load_request(SurfiClient *client, WebKitNetworkRequest *request);
void surfi_client_load_string(SurfiClient *client, const char *content, const char *mime_type,
							  const char *encoding, const char *base_uri);
void surfi_client_load_uri(SurfiClient *client, const char *uri);
unsigned int surfi_client_mark_text_matches(SurfiClient *client, const char *string, bool case_sensitive, unsigned int limit);
void surfi_client_move_cursor(SurfiClient *client, GtkMovementStep step, int count);
void surfi_client_paste_clipboard(SurfiClient *client);
void surfi_client_redo(SurfiClient *client);
void surfi_client_reload(SurfiClient *client);
void surfi_client_reload_bypass_cache(SurfiClient *client);
bool surfi_client_search_text(SurfiClient *client, const char *text, bool case_sensitive, bool forward, bool wrap);
void surfi_client_select_all(SurfiClient *client);
void surfi_client_set_custom_encoding(SurfiClient *client, const char *encoding);
void surfi_client_set_editable(SurfiClient *client, bool flag);
void surfi_client_set_full_content_zoom(SurfiClient *client, bool full_content_zoom);
void surfi_client_set_highlight_text_matches(SurfiClient *client, bool highlight);
void surfi_client_set_maintains_back_forward_list(SurfiClient *client, bool flag);
void surfi_client_set_settings(SurfiClient *client, WebKitWebSettings *settings);
void surfi_client_set_transparent(SurfiClient *client, bool flag);
void surfi_client_set_view_mode(SurfiClient *client, WebKitWebViewViewMode mode);
void surfi_client_set_view_source_mode(SurfiClient *client, bool view_source_mode);
void surfi_client_set_zoom_level(SurfiClient *client, float zoom_level);
void surfi_client_stop_loading(SurfiClient *client);
Pixbuf* surfi_client_try_get_favicon_pixbuf(SurfiClient *client, int width, int height);
void surfi_client_undo(SurfiClient *client);
void surfi_client_unmark_text_matches(SurfiClient *client);
void surfi_client_zoom_in(SurfiClient *client);
void surfi_client_zoom_out(SurfiClient *client);
WebKitWebWindowFeatures* surfi_client_get_window_features(SurfiClient *client);
void* surfi_client_get_snapshot(SurfiClient *client); // TODO void* = cairo_surface_t*
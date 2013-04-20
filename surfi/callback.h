/* See LICENSE file for copyright and license details. */

void surfi_client_set_callback_close_web_view(SurfiClient *client,
	bool(*callback)(SurfiClient *client));
void surfi_client_set_callback_console_message(SurfiClient *client,
	bool(*callback)(SurfiClient *client, char *message, int line, char *source_id));
void surfi_client_set_callback_context_menu(SurfiClient *client,
	bool(*callback)(SurfiClient *client, GtkWidget *default_menu,
	     WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard));
void surfi_client_set_callback_copy_clipboard(SurfiClient *client,
	void(*callback)(SurfiClient *client));
void surfi_client_set_callback_create_plugin_widget(SurfiClient *client,
	void(*callback)(SurfiClient *client, char *mime_type, char *uri, GHashTable *param));
void surfi_client_set_callback_create_webview(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_cut_clipboard(SurfiClient *client,
	void(*callback)(SurfiClient *client));
void surfi_client_set_callback_database_quota_exceeded(SurfiClient *client,
	void(*callback)(SurfiClient *client, GObject *frame, GObject *database));
void surfi_client_set_callback_document_load_finished(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_download_requested(SurfiClient *client,
	void(*callback)(SurfiClient *client,GObject *download));
void surfi_client_set_callback_editing_began(SurfiClient *client,
	void(*callback)(SurfiClient *client));
void surfi_client_set_callback_editing_ended(SurfiClient *client,
	void(*callback)(SurfiClient *client));
void surfi_client_set_callback_entering_fullscreen(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitDOMHTMLElement *element));
void surfi_client_set_callback_frame_created(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_geolocation_policy_decision_cancelled(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_geolocation_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitGeolocationPolicyDecision *policy_decision));
void surfi_client_set_callback_hovering_over_link(SurfiClient *client,
	void(*callback)(SurfiClient *client, char *title, char *uri));
void surfi_client_set_callback_icon_loaded(SurfiClient *client,
	void(*callback)(SurfiClient *client, char *icon_uri));
void surfi_client_set_callback_leaving_fullscreen(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitDOMHTMLElement *element));
void surfi_client_set_callback_load_commited(SurfiClient *client,
	void (*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_load_error(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_load_finished(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_load_progress_changed(SurfiClient *client,
	void(*callback)(SurfiClient *client, int progress));
void surfi_client_set_callback_load_started(SurfiClient *client,
	void (*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_mime_type_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitNetworkRequest *request,
	                char *mimetype, WebKitWebPolicyDecision *policy_decision));
void surfi_client_set_callback_move_cursor(SurfiClient *client,
	bool(*callback)(SurfiClient *client, GtkMovementStep step, int count));
void surfi_client_set_callback_navigation_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client,  WebKitWebFrame *frame, WebKitNetworkRequest *request,
	                WebKitWebNavigationAction *navigation_action, WebKitWebPolicyDecision *policy_decision));
void surfi_client_set_callback_navigation_requested(SurfiClient *client,
	WebKitNavigationResponse(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitNetworkRequest *request));
void surfi_client_set_callback_new_window_policy_decision_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitNetworkRequest *request,
	                WebKitWebNavigationAction *navigation_action, WebKitWebPolicyDecision *policy_decision));
void surfi_client_set_callback_onload_event(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_paste_clipboard(SurfiClient *client,
	void(*callback)(SurfiClient *client));
void surfi_client_set_callback_populate_popup(SurfiClient *client,
	void(*callback)(SurfiClient *client, GtkMenu *menu));
void surfi_client_set_callback_print_requested(SurfiClient *client,
	bool(*callback)(SurfiClient *client, WebKitWebFrame *frame));
void surfi_client_set_callback_redo(SurfiClient *client,
	void(*callback)(SurfiClient *client));
void surfi_client_set_callback_resource_content_length_received(SurfiClient *client,
	void(*callback)(SurfiClient *client, WebKitWebFrame *frame, WebKitWebResource *resource, int length));
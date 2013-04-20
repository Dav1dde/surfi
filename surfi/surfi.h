/*
 * Represents the Surfi Client, holding all relevant
 * information, you should not access the members.
 *
 */
typedef struct SurfiClient {
	GtkWidget *window; // Offscreen window
	GtkWidget *view; // The webkit widget

	void *userptr; // custom user pointer passed to all callbacks

	bool (*on_close_web_view)(struct SurfiClient *client);
	bool (*on_console_message)(struct SurfiClient *client, char *message, int line, char *source_id);
	bool (*on_context_menu)(struct SurfiClient *client, GtkWidget *default_menu,
	                        WebKitHitTestResult *hit_test_result, bool triggered_with_keyboard);
	void (*on_copy_clipboard)(struct SurfiClient *client);
	void (*on_create_plugin_wdiget)(struct SurfiClient *client);
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
 * Sets the size of the offscreen webview.
 *
 */
void surfi_client_set_size(struct SurfiClient *c, int width, int height);

/*
 * Set a userptr for a SurfiClient.
 *
 */
void surfi_client_set_userptr(struct SurfiClient *c, void *ptr);

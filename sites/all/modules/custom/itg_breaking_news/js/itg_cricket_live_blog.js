/*
 * @file itg_breaking_news.js
 */

/*
 * @file itg_cricket_live_blog.js
 * Contains all functionality related to Cricket live Blog
 */

jQuery(document).ready(function () {
    var base_url = Drupal.settings.itg_cricket_live_blog.settings.base_url;
    var match_id = Drupal.settings.itg_cricket_live_blog.settings.match_id;
    var nid = Drupal.settings.itg_cricket_live_blog.settings.nid;
    if (match_id != false) {
        //load_more_after_interval();
        var flag_n = false;
        setInterval(function () {
            if (!flag_n) {
                flag_n = true;
                jQuery.ajax({
                    url: base_url + '/cricket_live_blog_content?match_id='+match_id,
                    type: "get",
                    //data: {"match_id": match_id},
                    success: function (d) {
                        if (d !== undefined) {
                            var data = JSON.parse(d);
                            if (data.status == 'success') {
                                jQuery("#bolgcontent").html(data.data);
                            } else {
                            }
                        }

                        flag_n = false;
                    }
                });
            }
        }, 5000);

    } else if (match_id === false && nid !== undefined) {
        var flag = false;
        var db_load_more = setInterval(function () {
            if (!flag) {
                flag = true;
                var current_inn = parseInt(jQuery("#bolgcontent .para-live-blog").last().attr('current-inn')) + 1;
                jQuery.ajax({
                    url: base_url + '/cricket_live_blog_content_db/' + nid + '/' + current_inn,
                    type: "get",
                    success: function (d) {
                        if (d !== undefined) {
                            var data = JSON.parse(d);
                            if (data.status == 'success' && data.data.length > 5) {
                                jQuery("#bolgcontent").append(data.data);
                            } else {
                                clearInterval(db_load_more);
                            }
                        }

                        flag = false;

                    }
                });
            }
        }, 5000);
    }

});

function load_more_after_interval() {
    var base_url = Drupal.settings.itg_cricket_live_blog.settings.base_url;
    var match_id = Drupal.settings.itg_cricket_live_blog.settings.match_id;
    var flag = false;
    var load_more = setInterval(function () {
        if (!flag) {
            flag = true;
            var last_commentary_id = jQuery("#bolgcontent .para-live-blog").last().attr('commentary-id');
            var current_inn = jQuery("#bolgcontent .para-live-blog").last().attr('current-inn');
            jQuery.ajax({
                url: base_url + '/cricket_live_blog_content?match_id='+match_id+'&commentary_id='+last_commentary_id+'&is_load_new=false&current_inn='+current_inn,
                type: "get",
                //data: {"match_id": match_id, "commentary_id": last_commentary_id, "is_load_new": false, "current_inn": current_inn},
                success: function (d) {
                    if (d !== undefined) {
                        var data = JSON.parse(d);
                        if (data.status == 'success' && data.data.length > 5) {
                            jQuery("#bolgcontent").append(data.data);
                        } else {
                            clearInterval(load_more);
                        }
                    }

                    flag = false;

                }
            });
        }
    }, 5000);

}
;

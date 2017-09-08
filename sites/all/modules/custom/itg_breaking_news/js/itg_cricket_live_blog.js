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
    setInterval(function () {
      jQuery.ajax({
        url: base_url + '/cricket_live_blog_content',
        type: "post",
        data: {"match_id":match_id},
        success: function (d) {
            var data = JSON.parse(d);
            console.log(data, 'data');
            if(data.status == 'success'){
                jQuery("#bolgcontent").html(data.data);
            }else{
                console.log('error');
            }
               
        }
      });
    }, 50000);

});
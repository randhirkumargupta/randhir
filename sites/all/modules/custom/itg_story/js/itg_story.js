// (function($) {
//            Drupal.behaviors.itg_story = {
//                attach: function(context, settings) {
//                    $('select[name="CI_PState"]').on("change", function() {
//                        var base_url = settings.itg_story.settings.base_url;
//                        $.ajax({
//                            url: base_url + "/personalinfo/get-city-list",
//                            method: 'post',
//                            data: {'tid': this.value, 'pid': $('input[name="productid"]').val()},
//                            success: function(data) {
//                                var select = $('select[name="CI_PCity"]');
//                                select.empty().append(data);
//                                select.data("selectBox-selectBoxIt").refresh();
//                            },
//                            error: function(request, status, error) {
//                                alert(request.responseText);
//                            }
//                        });
//                    });
//                }
//
//    };
//})(jQuery, Drupal, this, this.document);
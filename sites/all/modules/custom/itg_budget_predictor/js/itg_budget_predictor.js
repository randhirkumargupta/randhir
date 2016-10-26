/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_widgets = {
    attach: function (context, settings) {
        $(function ()
        {
            var isUpdated;
            jQuery("#sortable1, #sortable2, #sortable3, #sortable4").sortable(
            {
                connectWith: '.connectedSortable',
                update: function (event, ui) {
                    isUpdated = true;
                },
                stop: function (event, ui) {
                    if (isUpdated == true) {
                        //Do Something
                        jQuery.ajax(
                                {
                                    type: "POST",
                                    url: "ajax/budget-ranking",
                                    data:
                                            {
                                                sort1: jQuery("#sortable1").sortable('serialize'),
                                                sort2: jQuery("#sortable2").sortable('serialize'),
                                                sort3: jQuery("#sortable3").sortable('serialize')
                                            },
                                    success: function (html)
                                    {
                                        jQuery('.success').fadeIn(500);
                                    }
                                });
                    }
                }
            }).disableSelection();
        });

    }
};

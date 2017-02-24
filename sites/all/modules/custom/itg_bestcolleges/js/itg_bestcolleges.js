/*
 * @file itg_bestcolleges.js
 * Contains all functionality related to bestcolleges
 */
(function($) {
    Drupal.behaviors.itg_bestcolleges = {
        attach: function(context, settings) {
            var url = '';
            var baseurl = settings.itg_bestcolleges.settings.base_url;
            var year = settings.itg_bestcolleges.settings.year;
            $(".emerging_rhsdiv select").change(function() {
                var current_val = $(this).val();
                url = baseurl+'/bestcolleges/'+year+'/emerging/'+current_val;
                window.location.href = url;
            });
            $(".yearcompare_rhsdiv select#edit-yearcompare-stream").change(function() {
                var stcurrent_val = $(this).val();
                var year1comp_val = $( ".yearcompare_rhsdiv select#edit-yearcompare-yr1" ).val();
                var year2comp_val = $( ".yearcompare_rhsdiv select#edit-yearcompare-yr2" ).val();
                url = baseurl+'/bestcolleges/'+year1comp_val+'/'+year2comp_val+'/year-comparecollege/'+stcurrent_val;
                window.location.href = url;
            });
            $(".streamcompare_rhsdiv select#edit-streamcompare-rhs-yr").change(function() {
                var yrcurrent_val = $(this).val();
                var st1_val = $( ".streamcompare_rhsdiv select#edit-streamcompare-rhs-stream1" ).val();
                var st2_val = $( ".streamcompare_rhsdiv select#edit-streamcompare-rhs-stream2" ).val();
                url = baseurl+'/bestcolleges/'+yrcurrent_val+'/stream-comparecollege/'+st1_val+'/'+st2_val;
                window.location.href = url;
            });
            $(".clgdir_rhsdiv select").change(function() {
                var st1current_val = $(this).val();
                url = baseurl+'/bestcolleges/'+year+'/readyrecnor-directory-list/'+st1current_val;
                window.location.href = url;
            });
            $(".clgzone_rhsdiv select").change(function() {
                var st2current_val = $(this).val();
                url = baseurl+'/bestcolleges/'+year+'/zone-wise-list/'+st2current_val;
                window.location.href = url;
            });
            $(".htmlstatic_rhsdiv select").change(function() {
                var st3current_val = $(this).val();
                window.location.href = st3current_val;
            });
        }
    };
})(jQuery, Drupal, this, this.document);

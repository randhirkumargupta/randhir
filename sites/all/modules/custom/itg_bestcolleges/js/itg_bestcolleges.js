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
            $(".form-item-emerging-select select").change(function() {
                var current_val = $(this).val();
                url = baseurl+'/bestcolleges/'+year+'/emerging-colleges-rank/'+current_val;
                window.location.href = url;
            });
            $(".form-item-yearcompare-stream select").change(function() {
            //edit-yearcompare-yr1--2
                var stcurrent_val = $(this).val();
                var year1comp_val = $( ".form-item-yearcompare-yr1 select" ).val();
                var year2comp_val = $( ".form-item-yearcompare-yr2 select" ).val();
                url = baseurl+'/bestcolleges/'+year+'/compare-college/'+stcurrent_val+'/'+year1comp_val+'-'+year2comp_val;
                window.location.href = url;
            });
            $(".form-item-streamcompare-rhs-yr select").change(function() {
                var yrcurrent_val = $(this).val();
                var st1_val = $( ".form-item-streamcompare-rhs-stream1 select" ).val();
                var st2_val = $( ".form-item-streamcompare-rhs-stream2 select" ).val();
                url = baseurl+'/bestcolleges/'+year+'/compare-college/'+yrcurrent_val+'-'+st1_val+'-'+st2_val;
                window.location.href = url;
            });
            $(".form-item-clgdir-stream select").change(function() {
                var st1current_val = $(this).val();
                //arts-bestcollege
                url = baseurl+'/bestcolleges/'+year+'/'+st1current_val+'-'+'bestcollege';
                window.location.href = url;
            });
            $(".form-item-clgzone-select select").change(function() {
                var st2current_val = $(this).val();
                url = baseurl+'/bestcolleges/'+year+'/zonewiselist-'+st2current_val;
                window.location.href = url;
            });
            $(".htmlstatic_rhsdiv select").change(function() {
                var st3current_val = $(this).val();
                window.location.href = st3current_val;
            });

            // for city wise
            $('.best-college-city select').on('change', function () {
              var url = $(this).val(); // get selected value
              if (url) { // require a URL
                  window.location = url; // redirect
              }
              return false;
            });

            // replace url for image
             jQuery('.right_align_bestcollege .thumbnail-img img').each(function($) {
                var urlRelative = jQuery(this).attr("src");
                var urlAbsolute = urlRelative.replace('http://itgddev.indiatodayonline.in/s3/files/', "http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public/");

                jQuery(this).attr("src",urlAbsolute);
            });

             jQuery('.item-college img').each(function($) {
                var urlRelative = jQuery(this).attr("src");
                var urlAbsolute = urlRelative.replace('http://itgddev.indiatodayonline.in/s3/files/', "http://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public/");

                jQuery(this).attr("src",urlAbsolute);
            });



        }
    };
})(jQuery, Drupal, this, this.document);

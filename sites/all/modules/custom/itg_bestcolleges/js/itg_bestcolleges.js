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
                if(current_val != '_none') {
                    url = baseurl+'/bestcolleges/'+year+'/emerging-colleges-rank/'+current_val;
                    window.location.href = url;
                }

            });

            // For YEAR-WISE COMPARISON
            $(".form-item-yearcompare-stream select").change(function() {
                var stcurrent_val = $(this).val();
                var year1comp_val = $( ".form-item-yearcompare-yr1 select" ).val();
                var year2comp_val = $( ".form-item-yearcompare-yr2 select" ).val();
                if(stcurrent_val != '_none') {
                    if(year1comp_val != '_none' && year2comp_val != '_none' && year1comp_val != year2comp_val) {
                        url = baseurl+'/bestcolleges/'+year+'/compare-college/'+stcurrent_val+'/'+year1comp_val+'-'+year2comp_val;
                        window.location.href = url;
                    } else {
                        if(year1comp_val == year2comp_val) {
                            alert("Please select different year for comparison");
                        } else {
                            alert("Please select both year for comparison");
                        }
                        jQuery('#edit-yearcompare-stream').val('_none');
                    }

                }
            });

            $(".form-item-yearcompare-yr1 select").change(function() {
                var year1comp_val = $(this).val();
                var year2comp_val = $( ".form-item-yearcompare-yr2 select" ).val();

                var stcurrent_val = $( ".form-item-yearcompare-stream select" ).val();

                if(stcurrent_val != '_none') {
                    if(year1comp_val != '_none' && year2comp_val != '_none' && year1comp_val != year2comp_val) {
                        url = baseurl+'/bestcolleges/'+year+'/compare-college/'+stcurrent_val+'/'+year1comp_val+'-'+year2comp_val;
                        window.location.href = url;
                    } else {
                        if(year1comp_val == year2comp_val) {
                            alert("Please select different year for comparison");
                        } else {
                            alert("Please select both year for comparison");
                        }
                        jQuery('#edit-yearcompare-stream').val('_none');
                    }

                }
            });

            $(".form-item-yearcompare-yr2 select").change(function() {
                var year2comp_val = $(this).val();
                var year1comp_val = $( ".form-item-yearcompare-yr1 select" ).val();

                var stcurrent_val = $( ".form-item-yearcompare-stream select" ).val();

                if(stcurrent_val != '_none') {
                    if(year1comp_val != '_none' && year2comp_val != '_none' && year1comp_val != year2comp_val) {
                        url = baseurl+'/bestcolleges/'+year+'/compare-college/'+stcurrent_val+'/'+year1comp_val+'-'+year2comp_val;
                        window.location.href = url;
                    } else {
                        if(year1comp_val == year2comp_val) {
                            alert("Please select different year for comparison");
                        } else {
                            alert("Please select both year for comparison");
                        }
                        jQuery('#edit-yearcompare-stream').val('_none');
                    }

                }
            });


            // End YEAR-WISE COMPARISON

            // For STREAM-WISE COMPARISON
            $(".form-item-streamcompare-rhs-yr select").change(function() {
                var yrcurrent_val = $(this).val();
                var st1_val = $( ".form-item-streamcompare-rhs-stream1 select" ).val();
                var st2_val = $( ".form-item-streamcompare-rhs-stream2 select" ).val();
                if(yrcurrent_val != '_none') {
                    if(st1_val != '_none' && st2_val != '_none' && st1_val != st2_val) {
                        url = baseurl+'/bestcolleges/'+year+'/compare-college/'+yrcurrent_val+'-'+st1_val+'-'+st2_val;
                        window.location.href = url;
                    } else {
                        if(st1_val == st2_val) {
                            alert("Please select different stream for comparison");
                        } else {
                            alert("Please select both stream for comparison");
                        }
                        jQuery('#edit-streamcompare-rhs-yr').val('_none');
                    }
                }
            });

            // for stream2

            $(".form-item-streamcompare-rhs-stream2 select").change(function() {
                var st2_val = $(this).val();
                var st1_val = $( ".form-item-streamcompare-rhs-stream1 select" ).val();
                var yrcurrent_val = $( ".form-item-streamcompare-rhs-yr select" ).val();
                if(yrcurrent_val != '_none') {
                    if(st1_val != '_none' && st2_val != '_none' && st1_val != st2_val) {
                        url = baseurl+'/bestcolleges/'+year+'/compare-college/'+yrcurrent_val+'-'+st1_val+'-'+st2_val;
                        window.location.href = url;
                    } else {
                        if(st1_val == st2_val) {
                            alert("Please select different stream for comparison");
                        } else {
                            alert("Please select both stream for comparison");
                        }
                        jQuery('#edit-streamcompare-rhs-yr').val('_none');
                    }
                }
            });

            $(".form-item-streamcompare-rhs-stream1 select").change(function() {
                var st1_val = $(this).val();
                var st2_val = $( ".form-item-streamcompare-rhs-stream2 select" ).val();
                var yrcurrent_val = $( ".form-item-streamcompare-rhs-yr select" ).val();
                if(yrcurrent_val != '_none') {
                    if(st1_val != '_none' && st2_val != '_none' && st1_val != st2_val) {
                        url = baseurl+'/bestcolleges/'+year+'/compare-college/'+yrcurrent_val+'-'+st1_val+'-'+st2_val;
                        window.location.href = url;
                    } else {
                        if(st1_val == st2_val) {
                            alert("Please select different stream for comparison");
                        } else {
                            alert("Please select both stream for comparison");
                        }
                        jQuery('#edit-streamcompare-rhs-yr').val('_none');
                    }
                }
            });


            // End STREAM-WISE COMPARISON

            $(".form-item-clgdir-stream select").change(function() {
                var st1current_val = $(this).val();
                //arts-bestcollege
                if(st1current_val != '_none') {
                    url = baseurl+'/bestcolleges/'+year+'/'+st1current_val+'-'+'bestcollege';
                    window.location.href = url;
                }
            });

            $(".form-item-clgzone-select select").change(function() {
                var st2current_val = $(this).val();
                if(st2current_val != '_none') {
                    url = baseurl+'/bestcolleges/'+year+'/zonewiselist-'+st2current_val;
                    window.location.href = url;
                }
            });
            $(".htmlstatic_rhsdiv select").change(function() {
                var st3current_val = $(this).val();
                if(st3current_val != '_none') {
                    window.location.href = st3current_val;
                }
            });

            // for city wise
            $('.best-college-city select').on('change', function () {
              var url = $(this).val(); // get selected value
              if (url && url != '_none') { // require a URL
                  window.location = url; // redirect
              }
              return false;
            });

            // for year
            $(".bestcollege_year_wise").change(function() {
                var bestcollege_year = $(this).val();
                var stream_arr = {2011:"844764", 2010:"844770", 2009:"844776", 2008:"844782", 2007:"844788", 2006:"844794", 2005:"844800"}
                if(bestcollege_year != '_none') {
                    if(bestcollege_year > 2011) {
                        url = baseurl+'/bestcolleges/'+bestcollege_year;
                    } else {
                        url = baseurl+'/bestcolleges/'+bestcollege_year+'/ranks/'+stream_arr[bestcollege_year];
                    }
                    window.location.href = url;
                }
            });

            jQuery('.vertical-menu-parent').hide();

        }
    };
})(jQuery, Drupal, this, this.document);

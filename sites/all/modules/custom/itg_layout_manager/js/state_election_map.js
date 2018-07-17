/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($) {
    Drupal.behaviors.itg_layout = {
        attach: function (context, settings) {
            var index = settings.itg_layout_manager.settings.index;
            var json_data = settings.itg_layout_manager.settings.json_data;
            json_data = jQuery.parseJSON(json_data);
            jQuery(function () {
                var ids = "container_" + index;
                var data = json_data;
                var combined = [];
                var colorArray = [];
                var aName = data.election.aName;
                var aSeats = data.election.aSeats;
                var aSeatOthers = data.election.aSeatOthers;
                var aappos = 0;
                var aapcolor = "";
                var aapname = "";
                var aapseats = "";
                var ty = 0;
                for (var x = 0; x < data.election.items.length; x++)
                {
                    if (data.election.items[x].pName.toLowerCase() != "bjp+") {
                        colorArray[ty] = data.election.items[x].pColor;
                        combined.push([data.election.items[x].pName, (parseInt(data.election.items[x].pLead) + parseInt(data.election.items[x].pWon))]);
                        ty++;
                    } else {
                        aapcolor = data.election.items[x].pColor;
                        aappos = data.election.items[x].pColor;
                        aapname = data.election.items[x].pName;
                        aapseats = (parseInt(data.election.items[x].pLead) + parseInt(data.election.items[x].pWon));
                    }
                }
                var showtooltip = true;
                if (aSeatOthers == 0) {
                    jQuery("#resultawaited").show();
                    colorArray[ty] = "#A2A9AD";
                    combined.push(["Result Awaited", "1"]);
                    showtooltip = false;
                } else {

                    colorArray[(parseInt(data.election.items.length) - 1)] = aapcolor;
                    combined.push([aapname, aapseats]);
                }


                var combined = [];
                var colorArray = [];
                var aName = data.election.aName;
                var aSeats = data.election.aSeats;
                var aSeatOthers = data.election.aSeatOthers;
                var aappos = 0;
                var aapcolor = "";
                var aapname = "";
                var aapseats = "";
                var colindex = 0;
                var shets = [];
                var apname = [];
                var apcolor = [];
                for (var x = 0; x < data.election.items.length; x++)
                {
                    if (data.election.items[x].pName.toLowerCase() != "bjp+") {
                        colorArray[colindex] = data.election.items[x].pColor;
                        apname.push(data.election.items[x].pName);
                        apcolor.push(data.election.items[x].pColor);
                        shets.push(parseInt(data.election.items[x].pLead) + parseInt(data.election.items[x].pWon));
                        combined.push([data.election.items[x].pName, (parseInt(data.election.items[x].pLead) + parseInt(data.election.items[x].pWon))]);
                        colindex++;
                    } else {
                        aapcolor = data.election.items[x].pColor;
                        aappos = data.election.items[x].pColor;
                        aapname = data.election.items[x].pName;
                        aapseats = (parseInt(data.election.items[x].pLead) + parseInt(data.election.items[x].pWon));
                    }
                }
                var showtooltip = true;
                if (aSeatOthers == 0) {
                    jQuery("#resultawaited").show();
                    colorArray[colindex] = "#A2A9AD";
                    combined.push(["Result Awaited", "1"]);
                    showtooltip = false;
                } else {

                    colorArray[(parseInt(data.election.items.length) - 1)] = aapcolor;
                    combined.push([aapname, aapseats]);
                }
                loadStateTable(apname, shets, apcolor);
                jQuery("#" + ids).highcharts({
                    colors: colorArray,
                    chart: {
                        plotBackgroundColor: null,
                        plotBorderWidth: 0,
                        plotShadow: false
                    },
                    title: {
                        text: "Total " + aSeatOthers + "/" + aSeats,
                    },
                    tooltip: {
                        enabled: showtooltip,
                        pointFormat: "<b>{point.y}</b>"
                    },
                    plotOptions: {
                        pie: {
                            allowPointSelect: true,
                            cursor: "pointer",
                            dataLabels: {
                                enabled: false
                            }
                        }
                    },
                    series: [{
                            type: "pie",
                            name: "Seats",
                            data: combined
                        }]
                });

            });
        }

    };
})(jQuery, Drupal, this, this.document);
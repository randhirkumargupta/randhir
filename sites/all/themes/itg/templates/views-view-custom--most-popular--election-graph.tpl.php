<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>

<?php foreach ($rows as $index => $row): ?>
    <div class="col-md-6 mt-50">
        <div class="itg-widget">
            <div class="droppable <?php print $gray_bg_layout; ?>">
                <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">


                    <div class="data-holder" id="itg-block-1"> <div id="container_<?php echo $index;?>" style="min-width: 310px; height: 238px; max-width: 600px; margin: 0 auto"></div>
                        <?php
                        $jsondata = file_get_contents($row['field_election_party_tally']);
                        $jsondata = '{"election": {"aName": "DELHI","aFullName": "DELHI","aFullNameHindi": "DELHI","aSeats": "70","aSeatOthers": "70","aColor": "","aColorOthers": "","items": [{"pName": "AAP","pColor":"#DDBC0F","pfullName":"AAP","pLead":"0","pWon": "67"},{"pName": "BJP+","pColor":"#F57B19","pfullName":"BJP+","pLead":"0","pWon": "3"},{"pName": "CONG","pColor":"#018fff","pfullName":"CONG","pLead":"0","pWon": "0"},{"pName": "OTH","pColor":"#9933ff","pfullName":"OTH","pLead":"0","pWon": "0"}]}}';
                        $jsondata = json_decode($jsondata);
                        print '<table cellspacing="0" cellpadding="8" border="0" width="100%" id="allianceTable_delhi" class="schedule2"><tbody>
<tr style="height:40px;"><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>
';


                        foreach ($jsondata->election->items as $elction_telly_data) {
                          
                            print '<tr style="background-color:#ffffff;"><td class="padtext"><span style="background:'.$elction_telly_data->pColor.'; width:5px; height:20px; display:inline-block; margin:0 10px -5px -14px"></span>'.ucfirst($elction_telly_data->pName).'</td>
<td>'.$elction_telly_data->pLead.'</td>
<td>'.$elction_telly_data->pWon.'</td>
<td>'.$elction_telly_data->pWon.'</td></tr>';
                        }

                        print '
</tbody>


</table>';
                        ?>  
                    </div>
                </div>             
            </div>
        </div>
    </div>

    <script type="text/javascript">
        $(function() {
            var ids = "container_<?php echo $index; ?>";
            var data = {"election": {"aName": "DELHI", "aFullName": "DELHI", "aFullNameHindi": "DELHI", "aSeats": "70", "aSeatOthers": "70", "aColor": "", "aColorOthers": "", "items": [{"pName": "AAP", "pColor": "#DDBC0F", "pfullName": "AAP", "pLead": "0", "pWon": "67"}, {"pName": "BJP+", "pColor": "#F57B19", "pfullName": "BJP+", "pLead": "0", "pWon": "3"}, {"pName": "CONG", "pColor": "#018fff", "pfullName": "CONG", "pLead": "0", "pWon": "0"}, {"pName": "OTH", "pColor": "#9933ff", "pfullName": "OTH", "pLead": "0", "pWon": "0"}]}};
            var combined = [];
            var colorArray = [];
            var aName = data.election.aName;
            var aSeats = data.election.aSeats;
            var aSeatOthers = data.election.aSeatOthers;
            var aappos = 0;
            var aapcolor = '';
            var aapname = '';
            var aapseats = '';
            var ty = 0;
            for (var x = 0; x < data.election.items.length; x++)
            {
                if (data.election.items[x].pName.toLowerCase() != 'bjp+') {
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
                $('#resultawaited').show();
                colorArray[ty] = '#A2A9AD';
                combined.push(['Result Awaited', '1']);
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
            var aapcolor = '';
            var aapname = '';
            var aapseats = '';
            var colindex = 0;
            for (var x = 0; x < data.election.items.length; x++)
            {
                if (data.election.items[x].pName.toLowerCase() != 'bjp+') {
                    colorArray[colindex] = data.election.items[x].pColor;
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
                $('#resultawaited').show();
                colorArray[colindex] = '#A2A9AD';
                combined.push(['Result Awaited', '1']);
                showtooltip = false;
            } else {

                colorArray[(parseInt(data.election.items.length) - 1)] = aapcolor;
                combined.push([aapname, aapseats]);
            }

            $('#' + ids).highcharts({
                colors: colorArray,
                chart: {
                    plotBackgroundColor: null,
                    plotBorderWidth: 0,
                    plotShadow: false
                },
                title: {
                    text: aName + ' (' + aSeatOthers + '/' + aSeats + ')',
                    align: 'center',
                    verticalAlign: 'middle',
                    y: 37
                },
                tooltip: {
                    enabled: showtooltip,
                    pointFormat: '<b>{point.y}</b>'
                },
                plotOptions: {
                    pie: {
                        dataLabels: {
                            enabled: false,
                            distance: -50,
                            style: {
                                fontWeight: 'bold',
                                color: 'white',
                                textShadow: '0px 1px 2px black'
                            }
                        },
                        startAngle: -90,
                        endAngle: 90,
                        center: ['50%', '55%']
                    }
                },
                series: [{
                        type: 'pie',
                        name: '',
                        innerSize: '60%',
                        data: combined
                    }]
            });
        });


    </script>
    </head>
    <body>
        <script src="https://code.highcharts.com/highcharts.js"></script>


      
    <?php endforeach; ?>
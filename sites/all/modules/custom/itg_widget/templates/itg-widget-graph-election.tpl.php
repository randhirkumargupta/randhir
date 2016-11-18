<?php
if (!empty($data)) : global $base_url; ?>


<?php foreach ($data as $index => $row):  ?>
    <div class="col-md-6 mt-50">
        <div class="itg-widget">
            <div class="droppable <?php print $gray_bg_layout; ?>">
                <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">


                    <div class="data-holder" id="itg-block-1"> <div id="container_<?php echo $index;?>" style="min-width: 310px; height: 238px; max-width: 600px; margin: 0 auto"></div>
                        <?php
                    
                        $jsondata = file_get_contents($row->field_election_constituency_tall);
                        $jsondata_orig = '{"election": {"aName": "DELHI", "aFullName": "DELHI", "aFullNameHindi": "DELHI", "aSeats": "70", "aSeatOthers": "70", "aColor": "", "aColorOthers": "", "items": [{"pName": "AAP", "pColor": "#DDBC0F", "pfullName": "AAP", "pLead": "0", "pWon": "67"}, {"pName": "BJP+", "pColor": "#F57B19", "pfullName": "BJP+", "pLead": "0", "pWon": "3"}, {"pName": "CONG", "pColor": "#018fff", "pfullName": "CONG", "pLead": "0", "pWon": "0"}, {"pName": "OTH", "pColor": "#9933ff", "pfullName": "OTH", "pLead": "0", "pWon": "0"}]}}';
                        
                        $jsondata = json_decode($jsondata_orig);
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

   
    </head>
    <body>
        


      
    <?php endforeach; ?>
<?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>

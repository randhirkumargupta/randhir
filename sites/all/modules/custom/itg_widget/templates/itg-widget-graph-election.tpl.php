<?php
if (!empty($data)) : global $base_url; ?>


<?php 
 $classrow=6;
 $rowcounter=ceil(12/count($data));
 if(count($data)<=2)
 {
     $classrow="col-md-$rowcounter";
 } else if(count($data)>2)
 {
     $classrow="col-el-".count($data);
 }
foreach ($data as $index => $row):  ?>
    <div class="<?php echo $classrow;?> mt-50">
        <div class="itg-widget">
            <div class="droppable <?php print $gray_bg_layout; ?>">
                <div class="widget-wrapper <?php print $widget_data['itg-block-1']['widget_name']; ?>">


                    <div class="data-holder"> 
                        <div class="graph-design">
                            <div id="container_<?php echo $index;?>"></div>
                            <div class="divider"></div>                                
                        </div>
                        
                        <?php
                    
                        $jsondata = file_get_contents($row->field_election_constituency_tall);
                        $jsondata_orig = '{"election": {"aName": "DELHI", "aFullName": "DELHI", "aFullNameHindi": "DELHI", "aSeats": "70", "aSeatOthers": "70", "aColor": "", "aColorOthers": "", "items": [{"pName": "AAP", "pColor": "#DDBC0F", "pfullName": "AAP", "pLead": "0", "pWon": "67"}, {"pName": "BJP+", "pColor": "#F57B19", "pfullName": "BJP+", "pLead": "0", "pWon": "3"}, {"pName": "CONG", "pColor": "#018fff", "pfullName": "CONG", "pLead": "0", "pWon": "0"}, {"pName": "OTH", "pColor": "#9933ff", "pfullName": "OTH", "pLead": "0", "pWon": "0"}]}}';
                        
                        $jsondata = json_decode($jsondata_orig);
                        print '<table cellspacing="0" cellpadding="8" border="0" width="100%" id="allianceTable_delhi" class="schedule2"><tbody>
<tr><th></th><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>
';


                        foreach ($jsondata->election->items as $elction_telly_data) {
                          
                            print '<tr><td class="party-color" style="background:'.$elction_telly_data->pColor.'"></td><td class="padtext">'.ucfirst($elction_telly_data->pName).'</td>
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

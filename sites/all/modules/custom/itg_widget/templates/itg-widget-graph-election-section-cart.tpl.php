<?php
ob_clean();
if (!empty($data)) : global $base_url, $theme;
  ?>


  <?php
  global $base_url;
  $classrow = 6;
  $rowcounter = ceil(12 / count($data));
  if (count($data) <= 2) {
    $classrow = "col-md-$rowcounter";
  } else if (count($data) > 2) {
    if (count($data) > 5) {
      $datacount = 5;
    } else {
      $datacount = count($data);
    }
    $classrow = "col-el-5";
  }
  ?>
  <div class="election-page">
      <div class="election-graph">
          <?php
          foreach ($data as $index => $row):
            $rand = rand(1, 999999);
            $jsondata = file_get_contents($row->field_election_constituency_tall_value);
            if (is_valid_json($jsondata)) {
              ?>
              <script>
                jQuery(function () {

                    var ids = "container_<?php echo $rand; ?>";
                    var data = '<?php echo $jsondata; ?>';
                    data = JSON.parse(data);
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
                    if (data != "") {
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
                        for (var x = 0; x < data.election.items.length; x++)
                        {
                            if (data.election.items[x].pName.toLowerCase() != "bjp+") {
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
                            jQuery("#resultawaited").show();
                            colorArray[colindex] = "#A2A9AD";
                            combined.push(["Result Awaited", "1"]);
                            showtooltip = false;
                        } else {

                            colorArray[(parseInt(data.election.items.length) - 1)] = aapcolor;
                            combined.push([aapname, aapseats]);
                        }

                        jQuery("#" + ids).highcharts({
                            colors: colorArray,
                            chart: {
                                plotBackgroundColor: null,
                                plotBorderWidth: 0,
                                plotShadow: false
                            },
                            title: {
                                text: aSeatOthers + "/" + aSeats + "<br>" + aName,
                                align: "center",
                                verticalAlign: "middle",
                                y: 12
                            },
                            tooltip: {
                                enabled: showtooltip,
                                pointFormat: "<b>{point.y}</b>"
                            },
                            plotOptions: {
                                pie: {
                                    dataLabels: {
                                        enabled: false,
                                        distance: -50,
                                        style: {
                                            fontWeight: "bold",
                                            color: "white",
                                            textShadow: "0px 1px 2px black"
                                        }
                                    },
                                    startAngle: -90,
                                    endAngle: 90,
                                    center: ["50%", "55%"]
                                }
                            },
                            series: [{
                                    type: "pie",
                                    name: "",
                                    innerSize: "60%",
                                    data: combined
                                }]
                        });
                    }
                });</script>

              <div class="<?php echo $classrow; ?>">
                  <?php
                    $terms = taxonomy_get_parents_all($row->field_election_state_tid);
                    $terms = array_reverse($terms);
                    $section = $terms[0]->tid;
                  ?>
                  <a href="<?php echo $base_url . '/state-election/' . $section . '/' . $row->field_election_state_tid ?>" >
                      <div class="graph-design">
                          <div id="container_<?php echo $rand; ?>"></div>
                          <div class="divider"></div>                                
                      </div>
                      <?php
                      $jsondata = file_get_contents($row->field_election_constituency_tall_value);
                      $jsondata = json_decode($jsondata);

                      if (!empty($jsondata)) {
                        print '<table cellspacing="0" cellpadding="8" border="0" width="100%" id="allianceTable_delhi" class="schedule2"><tbody>
<tr><th></th><th>PARTIES</th><th>LEADS</th><th>WON</th><th>TOTAL</th></tr>
';
                      }


                      foreach ($jsondata->election->items as $elction_telly_data) {
                        $total_result = (int) $elction_telly_data->pWon + (int) $elction_telly_data->pLead;
                        print '<tr><td class="party-color" style="background:' . $elction_telly_data->pColor . '"></td><td class="padtext">' . ucfirst($elction_telly_data->pName) . '</td>
<td>' . $elction_telly_data->pLead . '</td>
<td>' . $elction_telly_data->pWon . '</td>
<td>' . $total_result . '</td></tr>';
                      }

                      print '
</tbody>


</table><div class="social-share">
                    <ul>
                        <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                        <li><a title="share on facebook" class="facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $fb_share_title . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $src . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                        <li><a  title="share on twitter" class="twitter def-cur-pointer" onclick="twitter_popup(' . "'" . urlencode($search_title) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')"><i class="fa fa-twitter"></i></a></li>
                        <li><a title="share on google+" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google def-cur-pointer"></a></li>
                    </ul>
                </div>';
                      ?>  
                  </a>

              </div>




            <?php } ?>
            </a>
  <?php endforeach; ?>
      </div>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>

<?php endif; ?>

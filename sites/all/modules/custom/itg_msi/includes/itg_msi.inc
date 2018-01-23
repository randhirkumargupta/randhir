<?php
/**
 * Functionality to check title is duplicate OR not
 * Call through ajax function
 */
function itg_msi_check_duplicate_title() {
    $type = arg(1);
    $nid = arg(2);
    $title = $_POST['title'];
    $itgQuery = db_select('node', 'itg');

    if (empty($nid)) {
        $itgQuery->fields('itg', array('title'))
                ->condition('title', $title, '=')
                ->condition('type', $type, '=');
    }
    else {
        $itgQuery->fields('itg', array('title'))
                ->condition('title', $title, '=')
                ->condition('type', $type, '=')
                ->condition('nid', $nid, '!=');
    }

    $itgResult = $itgQuery->execute()->fetchObject();
    if (isset($itgResult->title) && strcasecmp($title, $itgResult->title) == 0) {
        echo ($type == 'astro') ? 'false' : drupal_json_encode(array('Code' => 1));
    }
    else {
        echo ($type == 'astro') ? 'true' : drupal_json_encode(array('Code' => 0));
    }
}

/**
 * Autocomplete on title(date field) of issue listing
 * @param string $title
 */
function itg_msi_autocomplete_content($title) {

    if (strlen(trim($title)) > 0) {
        $content_type = arg(1);
        $options = '';
        $title = strtolower(trim($title));
        $query = db_select('field_data_field_issue_title', 'c');
        $query->fields('c', array('field_issue_title_value'));
        $query->condition('field_issue_title_value', '%' . $title . '%', 'LIKE');
        $query->condition('c.bundle', $content_type, '=');
        $query->range(0, 20);

        $result = $query->execute();
        while ($record = $result->fetchAssoc()) {
            $options[date('Y-m-d', strtotime($record['field_issue_title_value']))] = date('m/d/Y', strtotime($record['field_issue_title_value']));
        }
        drupal_json_output($options);
    }
}

/**
 * Function for itg_update_external_url().
 */
function itg_update_external_url() {
	$csv = array_map('str_getcsv', file('/var/www/html/itgcms/field_story_external_url.csv'));
    array_shift($csv); //remove headers
    $i=1;
    $nids = array();
    $array = array(
'20145',
'20153',
'20158',
'20161',
'20168',
'20171',
'20175',
'20184',
'20185',
'20193',
'20194',
'20195',
'20197',
'20201',
'20204',
'20205',
'20207',
'20211',
'20211',
'20214',
'20215',
'20216',
'20222',
'20223',
'20224',
'20225',
'20228',
'20230',
'20237',
'20238',
'20243',
'20247',
'20250',
'20251',
'20254',
'20257',
'20262',
'20265',
'20270',
'20275',
'20283',
'20285',
'20286',
'20292',
'20295',
'20296',
'20297',
'20299',
'20306',
'20321',
'20323',
'20333',
'20337',
'20338',
'20339',
'20340',
'20343',
'20344',
'20347',
'20353',
'20368',
'20369',
'20372',
'20373',
'20374',
'20375',
'20382',
'20384',
'20387',
'20444',
'20445',
'20449',
'20452',
'20454',
'20457',
'20460',
'20466',
'20468',
'20469',
'20477',
'20484',
'20486',
'20488',
'20498',
'20500',
'20502',
'20503',
'20505',
'20509',
'20513',
'20514',
'20517',
'20518',
'20522',
'20523',
'20524',
'20524',
'20525',
'20532',
'20536',
'20540',
'20542',
'20543',
'20550',
'20551',
'20552',
'20554',
'20559',
'20560',
'20574',
'20581',
'20583',
'20586',
'20592',
'20596',
'20597',
'20598',
'20603',
'20607',
'20608'
);

foreach ($array as $rows) {
	foreach ($csv as $row) {
		if( strpos( $row[0], 'http://indiatoday.intoday.in/gallery/' ) !== false && strpos( $row[0], $rows) !== false) {
			$data[$rows] = $row[0];
		}	
	}	
}
	
foreach ($data as $key => $res) {
	$sourceid1[] = $key;
	$resArr = explode('http://indiatoday.intoday.in/', $res);
	if( strpos( $resArr[1], '#' ) !== false) {
		$dataArr = explode('#', $res);
		$resArr = explode('http://indiatoday.intoday.in/', $dataArr[0]);
		$res1[$key] = $resArr[1];
	} else {
	    $res1[$key] = $resArr[1];
	    	
	}		

}
						
$ques = db_select('migrate_map_itgphotogallery','s')					
						->fields('s', array('sourceid1', 'destid1'))
						->condition('sourceid1' , $sourceid1, 'IN')
						->execute();
					$res = $ques->fetchAll(PDO::FETCH_ASSOC);			
		foreach ($res as $value) {
		  if ($value['destid1']) {
			$source[$value['sourceid1']] = $value['destid1'];			
		  }  	  
		}
		
	
$table = '<table align="left" border="1" cellpadding="3" cellspacing="0">';			
$i=0;
foreach ($source as $keys => $values) {
	$table .= '<tr>';
	$table .= '<td>'.$i.'</td>';
    $table .= '<td>'.$res1[$keys].'</td>';
    $table .= '<td>'.$keys.'</td>';
    $table .= '<td>'.$values.'</td>';
    $table .= '</tr>';
    $i++;
}													

print $table .= '</table>';  
					
}









	

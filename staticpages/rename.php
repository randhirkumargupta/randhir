<?php
$array = array();
$dir = $_SERVER['DOCUMENT_ROOT'].'/staticpages';
//die();
$aa = listFolderFiles($dir,$array);
//print_r($aa);
die();
scanParentDir($dir);
rename_files($dir);
function rename_files($dir){

	$files = scandir($dir);
	unset($files[0],$files[1]);
	foreach ($files as $oldname){
		$newname1 = str_replace('?','-@@-',$oldname);
		$newname = str_replace(':','@--@',$newname1);
		rename ($dir.'/'.$oldname, $dir.'/'.$newname);
	}

}

function listFolderFiles($dir, &$array){
    $ffs = scandir($dir);
    unset($ffs[array_search('.', $ffs, true)]);
    unset($ffs[array_search('..', $ffs, true)]);
    if (count($ffs) < 1)
        return;
    foreach($ffs as $ff){
        if(!is_dir($dir.'/'.$ff)){
			$array[] = $dir.'/'.$ff;
			//echo $dir.'/'.$ff;
			//echo "<br>";
			$newname1 = str_replace('?','-@@-',$dir.'/'.$ff);
		    $newname = str_replace(':','@--@',$newname1);
		    rename ($dir.'/'.$ff, $newname);
		
		}
        if(is_dir($dir.'/'.$ff)) listFolderFiles($dir.'/'.$ff, $array);     
    }
    //print_r($array);
}

function scanParentDir($dir){
    $directories = scandir($dir);
    //print_r($directories);
    foreach($directories as $dir2){
		 //check jsp files
		 $new_fname = strstr($dir2, '.jsp');
		 if(!$new_fname && $dir2 != '.' && $dir2 != '..'){
            //echo "".$dir."is folder";
            echo $dir.'/'.$dir2;
            rename_files($dir.'/'.$dir2);
            scanParentDir($dir.'/'.$dir2);
        }
        ////check html files
        $html_fname = strstr($dir2, '.html');
		 if(!$html_fname && $dir2 != '.' && $dir2 != '..'){
            //echo "".$dir."is folder";
            echo $dir.'/'.$dir2;
            rename_files($dir.'/'.$dir2);
            scanParentDir($dir.'/'.$dir2);
        }
    }
}

?>

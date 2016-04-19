<?php
/**
   Copyright 2013 AlchemyAPI

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


	require_once('alchemyapi.php');
	$alchemyapi = new AlchemyAPI('cd95bc47470dedf7e5002748636e78848cd0a9f4');


	$myText = "Mentha oil futures gain 0.24% as demand picks up";

	$response = $alchemyapi->keywords('text',$myText, array('sentiment'=>1));

	if ($response['status'] == 'OK') {
		echo '## Response Object ##', PHP_EOL;
		echo print_r($response);
    

		echo PHP_EOL;
		echo '## Keywords ##', PHP_EOL;
		foreach ($response['keywords'] as $keyword) {
			echo 'keyword: ', $keyword['text'], PHP_EOL;
			echo 'relevance: ', $keyword['relevance'], PHP_EOL;
			echo 'sentiment: ', $keyword['sentiment']['type']; 			
			if (array_key_exists('score', $keyword['sentiment'])) {
				echo ' (' . $keyword['sentiment']['score'] . ')', PHP_EOL;
			} else {
				echo PHP_EOL;
			}
			echo PHP_EOL;
		}
	} else {
		echo 'Error in the keyword extraction call: ', $response['statusInfo'];
	}
?>

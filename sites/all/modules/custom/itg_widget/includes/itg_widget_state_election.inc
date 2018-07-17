<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function state_election_sosorry_data() {
  $section = arg(1);
 $dataarray =  get_layout_details_block($section,'page--special_election',1);
 return $dataarray['itg-block-10'];
}

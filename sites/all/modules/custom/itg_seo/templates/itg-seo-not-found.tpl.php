<?php
/**
 * Template page for not found page
 * 
 * @file: itg-seo-not-found.tpl.php
 */
global $base_url;
?>
<div class="page-error">
  <div class="row">
    <div class="col-md-6">
      <div class="page-error-pic">
        <img src="<?php echo $base_url . '/sites/all/themes/itg/images/error_404.png';?>" alt=""/>
        <p>The page you are looking for is no longer available.</p>
      </div>
    </div>
    <div class="col-md-6">
      <p class="go-back">
        I want to go <a href="#">BACK</a> from where I came </br> Open the <a href="#">India Today</a> homepage for me
      </p>
      <span class="error-or">OR</span>
      <h3>Check out Latest Headlines</h3>
      <ul class="latest-headlines-list">
        <li><span class="red">See pics:</span> Jennifer, Ragini, Mouni step out in their sexiest best</li>
        <li>Priyanka Chopra reveals her favourite Quantico episode in a Twitter chat</li>
        <li>TV newbie Tridha Choudhury happy to be compared to Alia Bhatt</li>
        <li>7 lesser-known facts about Bigg Boss hottie Kishwer Merchant</li>
      </ul>
    </div>
  </div>
</div>
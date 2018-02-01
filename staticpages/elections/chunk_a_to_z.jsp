








 



<script>
/* atoz slider */
	$(document).ready(function(e) {

		lenb = $('.belt_large h6').length;
		
		$('.belt_large').width(((100*lenb)+10));
		
		$('.parrow').css('opacity', '0.5');
		countern = 1;

        $('.parrow').click(function(){

			if (countern == 1)
				{
					$('.parrow').css('opacity', '0.5');	
				}
				else 
				{
					$('.belt_large').animate({
						left : '+=100'
					});	
					countern -=1;
					$('.narrow').css('opacity', '1');
				}
			});
			
		 $('.narrow').click(function(){
				if (countern <= lenb - 6)
				{
					$('.belt_large').animate({
					left : '-=100'
					});
					countern +=1;
					$('.parrow').css('opacity', '1');	
				}
				else
				{
					$('.narrow').css('opacity', '0.5');
				}
			});
			
			
		$('.atoz_slider h6').click(function(){
			$(this).children('img').animate({
				top : -105
			});
			
			$(this).children('div').animate({
				top : -105
			});
		});
			
			
    });
</script>
<style>

.boxcont_large { background-color: #FFFFFF; box-shadow: 2px 2px 10px 2px #CCCCCC; float: left; margin: 0 0 7%; min-height: inherit !important; width: 670px; }
.box_large { float: left; margin-bottom: 0; width: 100%; position: relative; height: 175px; overflow: hidden; }
 .box_large { color: #000000; font: 700 18px/22px Roboto, sans-serif; }

/*atoz slider css*/
.atoz_slider { width: 670px; position: relative; top: 0px; }
.atoz_slider h6 { overflow: hidden; width: 88px; float: left; margin:24px 0 0 10px; cursor:pointer; }
.atoz_slider h6 b {background: none repeat scroll 0 0 #C3C3C3;
    color: #FFFFFF;
    display: block;
    font-family: roboto;
    font-size: 100px;
    font-weight: bolder;
    height: 101px;
    line-height: 100px;
    text-align: center;
    width: 88px;}
.atoz_slider h6 .hover_span { float:left;}
.atoz_slider h6 span { position: absolute; width: 313px; height: auto; line-height: 60px; padding: 7px; background: url("https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/subtitle_bg.png") repeat; color: #fff; z-index: 99999; bottom: 40px; font: bold 18px Roboto, sans-serif; }
.atoz_slider h6 span a { text-decoration: none; color: #000000; }
.atoz_slider h6 span a:hover { text-decoration: none; color: #5e5e5e; }
.belt_wrapper { height: 138px; overflow: hidden; width: 595px; margin-top: 28px; margin-left: 35px; }
.belt_large { margin-top: 0px; overflow: hidden; position: relative; height: 125px; width: 660px; }
.parrow,.parrow1 { background: url("https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/Left-arrow.gif") no-repeat scroll left top rgba(0, 0, 0, 0); display: block; float: left; height: 22px; position: absolute; text-indent: -9999px; top: 60px; width: 20px; left: 15px; }
.narrow,.narrow1 { background: url("https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/Right-arrow.gif") no-repeat scroll left top rgba(0, 0, 0, 0); display: block; float: right; height: 22px; text-indent: -9999px; width: 20px; position: absolute; top: 60px; right: 20px; }
.parrow1 { top: 48px; }
.narrow1 { top: 65px; width: 58px; }
 
.hover_span{width:88px; height:98px; background:#595959; color:#ffffff; float:left; display:none; margin:24px 0 0 10px;} 
/*a2z slider css end*/

.belt_large2 { margin-top: 0px; overflow: hidden; position: relative; height: 132px; width: 660px; }
.left_arrow,.left_arrow1 { background: url("https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/Left-arrow.gif") no-repeat scroll left top rgba(0, 0, 0, 0); display: block; float: left; height: 22px; position: absolute; text-indent: -9999px; top: 60px; width: 20px; left: 15px; }
.right_arrow,.right_arrow1{ background: url("https://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/election2014/Right-arrow.gif") no-repeat scroll left top rgba(0, 0, 0, 0); display: block; float: right; height: 22px; text-indent: -9999px; width: 20px; position: absolute; top: 60px; right: 20px; }
.left_arrow1 { top: 48px; }
.right_arrow1 { top: 65px; width: 58px; }
.slid-content { background: none repeat scroll 0 0 #666666;
    font-size: 12px;
    height: 100px;
    line-height: 14px;
    padding: 8px 5px;
    width: 78px;}
.slid-content a { color:#fff; padding:5px; text-decoration:none; width:50px}
.slid-content a:hover { color:#fff;  text-decoration:underline;}
.atoz_slider h6 img, .atoz_slider h6 div { position:relative;}


</style>


<div class="boxcont_large">

<div class="box_large">
    <div class="subhead ">
      <h2>A TO Z OF ELECTORAL POLITICS</h2>
    </div>
    <div class="atoz_slider">
      <div class="belt_wrapper">
        <div class="belt_large">
        
        
        
        
 <h6>
        <b>A</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18214">Alagiri, Advani, Ambedkar, Adarsh, AGP-IMDT, AFSPA, Affidavit</a></div>
          </h6>
	

 <h6>
        <b>B</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18215">Babri, Bofors, Bellary, Batla, Bhagalpur, Babuji, Bhatta, Bhanwari</a></div>
          </h6>
	

 <h6>
        <b>C</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18218">Cauvery water dispute, Countermanding of poll</a></div>
          </h6>
	

 <h6>
        <b>D</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18219">Dynasty politics, Dalits</a></div>
          </h6>
	

 <h6>
        <b>E</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18220">Emergency</a></div>
          </h6>
	

 <h6>
        <b>F</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18221">Feku, Fodder scam</a></div>
          </h6>
	

 <h6>
        <b>G</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18222">Godhra, Gujjar, Goa mining</a></div>
          </h6>
	

 <h6>
        <b>H</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18223">Hindu terror, Hurriyat</a></div>
          </h6>
	

 <h6>
        <b>I</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18224">India First, Indira Gandhi</a></div>
          </h6>
	

 <h6>
        <b>J</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18225">JP, Jan Aushadhi, Janata Party, Janata Dal</a></div>
          </h6>
	

 <h6>
        <b>L</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18226">Lok Satta, Left Front, Lingayat, Lankan Tamils</a></div>
          </h6>
	

 <h6>
        <b>M</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18227">Maoists, Muzaffarnagar, Meham, Mandal, Mahadalit</a></div>
          </h6>
	

 <h6>
        <b>N</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18228">NTR, Nagpur</a></div>
          </h6>
	

 <h6>
        <b>P</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18229">Pappu, Paid news, Purno Sangma</a></div>
          </h6>
	

 <h6>
        <b>Q</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18230">Quota</a></div>
          </h6>
	

 <h6>
        <b>R</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18231">RTI, Right to food, Reserved seat</a></div>
          </h6>
	

 <h6>
        <b>S</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18232">Seemandhra, Spectrum, Sanjay Gandhi, Solar scam</a></div>
          </h6>
	

 <h6>
        <b>T</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18233">Telangana, Third Front,</a></div>
          </h6>
	

 <h6>
        <b>V</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18234">Vidarbha, Vadra, Vokkaligas</a></div>
          </h6>
	

 <h6>
        <b>W</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18236">Withdrawal of nomination</a></div>
          </h6>
	

 <h6>
        <b>Y</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18235">YSR Congress</a></div>
          </h6>
	

 <h6>
        <b>Z</b>

          <div class="slid-content"><a href="a-to-z.jsp?id=18237">Z-plus security, Zakia Jafri</a></div>
          </h6>
	

        

         
         
        </div>
      </div>
      <span class="parrow" style="opacity: 1;"></span>
      <span class="narrow" style="opacity: 1;"></span> 
      </div>
      
  </div>



</div>

  
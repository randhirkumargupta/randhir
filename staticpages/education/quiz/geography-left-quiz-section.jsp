<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 385px;top:28px;}
	
	.left-quiz-section{padding:10px;}
	.q-box-section{ width:660px; height:66px; background:#fffde8;}
	.q-box{ width:40px; height:66px; line-height:66px; background:#f86e6c; text-align:center; color:#FFFFFF; float:left;}
	.q-box strong{ font-size:22px; font-weight:normal;}
	.q-pool {width: 580px;height: 66px;font-size: 16px;color: #9d9b9e;margin-left: 20px;float: left;}
	.radio-button-box{margin-left:40px;}
	.radio-button-box li{ list-style:none; float:left; margin-right:40px;padding: 18px 12px;}

	.active{
		background: #fffde8;padding: 18px 15px;-moz-border-radius: 0px 0px 10px 10px;
		-webkit-border-radius: 0px 0px 10px 10px;
		border-radius: 0px 0px 10px 10px;
		/*IE 7 AND 8 DO NOT SUPPORT BORDER RADIUS*/
	}
	.question-box{width: 675px;margin-bottom: 50px;float: left;}
	.styledRadio{  float:left; margin-right:5px; outline:0;}
	.radio-button-box label{ font-size:16px; color:#9d9b9e}
	.quiz-button{ width:675px; text-align:center; margin-top:20px;}

</style>

<div id="left-quiz-section">
	<div class="q-header"><h3>GEOGRAPHY</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">See how well you know about Incredible India</h2>
		<div class="left-quiz-section">
	    	<form name="geographyQuizForm" action="quiz-result.jsp" method="post" id="geographyQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						
						<div class="q-box"><strong>Q</strong>1</div>
						
						<div class="q-pool">
							<p>The Paithan (Jayakwadi) Hydro-electric project, completed with the help of Japan, is on which river?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Ganga"/>
								  <label for="q1"><span></span>Ganga</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Narmada"/>
								  <label for="q1"><span></span>Narmada</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Godavari"/>
								  <label for="q1"><span></span>Godavari</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>The pass located at the southern end of the Nilgiri Hills in south India is called</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="The Palghat gap"/>
								  <label for="q2"><span></span>The Palghat gap</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="The Bhorghat pass" />
								  <label for="q2"><span></span>The Bhorghat pass</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="The Bolan pass" />
								  <label for="q2"><span></span>The Bolan pass</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>The only state in India that produces saffron is</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Assam" />
								  <label for="q3"><span></span>Assam</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Himachal Pradesh" />
								  <label for="q3"><span></span>Himachal Pradesh</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Jammu and Kashmir" />
								  <label for="q3"><span></span>Jammu and Kashmir</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>The state having a largest area of forest cover in India is</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Assam" />
								  <label for="q4"><span></span>Assam</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Haryana" />
								  <label for="q4"><span></span>Haryana</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Madhya Pradesh" />
								  <label for="q4"><span></span>Madhya Pradesh</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>The percentage of earth surface covered by India is</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="2.4" />
								  <label for="q5"><span></span>2.4</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="3.6" />
								  <label for="q5"><span></span>3.6</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="2.7"/>
								  <label for="q5"><span></span>2.7</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>The oldest oil refinery in India is at</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Digboi, Assam" />
								  <label for="q6"><span></span>Digboi, Assam</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Koyali, near Baroda" />
								  <label for="q6"><span></span>Koyali, near Baroda</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Haldia, near Kolkata" />
								  <label for="q6"><span></span>Haldia, near Kolkata</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>The oldest mountains in India are</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Aravalis" />
								  <label for="q7"><span></span>Aravalis</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Vindhyas" />
								  <label for="q7"><span></span>Vindhyas</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Satpuras" />
								  <label for="q7"><span></span>Satpuras</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultGeographyQuiz" value="resultGeographyQuiz" id="resultGeographyQuizId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="geographyResult(geographyQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->




<script>
	function geographyResult(form) {
		var result="";
		for(index = 0; index < form.ques1.length; index++) {
			if(form.ques1[index].checked)
				result = "q1-" + form.ques1[index].value;
		}
		for(index = 0; index < form.ques2.length; index++) {
			if(form.ques2[index].checked)
				result = result + "#" + "q2-" + form.ques2[index].value;
		}
		for(index = 0; index < form.ques3.length; index++) {
			if(form.ques3[index].checked)
				result = result + "#" + "q3-" + form.ques3[index].value;
		}
		for(index = 0; index < form.ques4.length; index++) {
			if(form.ques4[index].checked)
				result = result + "#" + "q4-" + form.ques4[index].value;
		}
		for(index = 0; index < form.ques5.length; index++) {
			if(form.ques5[index].checked)
				result = result + "#" + "q5-" + form.ques5[index].value;
		}
		for(index = 0; index < form.ques6.length; index++) {
			if(form.ques6[index].checked)
				result = result + "#" + "q6-" + form.ques6[index].value;
		}
		for(index = 0; index < form.ques7.length; index++) {
			if(form.ques7[index].checked)
				result = result + "#" + "q7-" + form.ques7[index].value;
		}
		document.getElementById("resultWildlifeQuizId").value = result;
	}
	
	var selectedLi, elements, makeActive;
	selectedLi = '.radio-button-box li';
	elements = document.querySelectorAll(selectedLi);
	
	makeActive = function() {
		for(var index=0; index < elements.length; index++) {
			elements[index].classList.remove('active');
			this.classList.add('active');
		}		
	};
	for(var index=0; index < elements.length; index++)
		elements[index].addEventListener('mousedown', makeActive);
</script>
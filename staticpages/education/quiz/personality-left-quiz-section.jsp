<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 370px;top:28px;}
	
	.left-quiz-section{padding:10px;}
	.q-box-section{ width:660px; height:66px; background:#fffde8;}
	.q-box{ width:40px; height:66px; line-height:66px; background:#f86e6c; text-align:center; color:#FFFFFF; float:left;}
	.q-box strong{ font-size:22px; font-weight:normal;}
	.q-pool {width: 580px;height: 66px;font-size: 16px;color: #9d9b9e;margin-left: 20px;float: left;}
	.radio-button-box{margin-left:40px;}
	.radio-button-box li{ list-style:none; float:left; margin-right:60px;padding: 18px 15px;}

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

	<div class="q-header"><h3>PERSONALITY</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Let's check out your memory</h2>
		<div class="left-quiz-section">
	    	<form name="personalityQuizForm" action="quiz-result.jsp" method="post" id="personalityQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>1</div>
						<div class="q-pool">
							<p>Who is the first lady officer to lead inter service guard of honour?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Punita Arora"/>
								  <label for="q1"><span></span>Punita Arora</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Shweta Chauhan"/>
								  <label for="q1"><span></span>Shweta Chauhan</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Puja Thakur"/>
								  <label for="q1"><span></span>Puja Thakur</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Who was the first Indian to make a movie?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="Asha Bhonsle"/>
								  <label for="q2"><span></span>Asha Bhonsle</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Govind Phalke" />
								  <label for="q2"><span></span>Govind Phalke</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="V. Shantaram" />
								  <label for="q2"><span></span>V. Shantaram</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Who was known as "Lady with lamp"?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Florence Nightingale" />
								  <label for="q3"><span></span>Florence Nightingale</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Indira Gandhi" />
								  <label for="q3"><span></span>Indira Gandhi</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Marie Curie" />
								  <label for="q3"><span></span>Marie Curie</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Who was called a "Man Of Destiny"?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Napolean" />
								  <label for="q4"><span></span>Napolean</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Hitler" />
								  <label for="q4"><span></span>Hitler</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Nelson" />
								  <label for="q4"><span></span>Nelson</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>Who is legendary cartoonist who died recently?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="Abu Abraham" />
								  <label for="q5"><span></span>Abu Abraham</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="Barun Roy" />
								  <label for="q5"><span></span>Barun Roy</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="R.K Lakshman"/>
								  <label for="q5"><span></span>R.K Lakshman</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Which actress got Padma shri in 2014?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Aishwarya Rai" />
								  <label for="q6"><span></span>Aishwarya Rai</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Kareena Kapoor" />
								  <label for="q6"><span></span>Kareena Kapoor</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Vidya Balan" />
								  <label for="q6"><span></span>Vidya Balan</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Which actor got Padma Bhushan in 2014?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Amitabh Bachhan" />
								  <label for="q7"><span></span>Amitabh Bachhan</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Kamala Hassan" />
								  <label for="q7"><span></span>Kamala Hassan</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Rajinikanth" />
								  <label for="q7"><span></span>Rajinikanth</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultPersonalityQuiz" value="resultPersonalityQuiz" id="resultPersonalityQuizId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="personalityResult(personalityQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->
<script>
	function personalityResult(form) {
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
		document.getElementById("resultPersonalityQuizId").value = result;
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





















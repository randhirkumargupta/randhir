
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 400px;top:28px;}
	
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
	<div class="q-header"><h3>WILDLIFE</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">How much do you know about animals?</h2>
		<div class="left-quiz-section">
	    	<form name="wildlifeQuizForm" action="quiz-result.jsp" method="post" id="wildlifeQuizFormId">
	    		<input type="hidden" name="wildlifeQuizPart" value="null"/>
	    		
						<div class="question-box">
							<div class="q-box-section">
								
								<div class="q-box"><strong>Q</strong>1</div>
								
								<div class="q-pool">
									<p>Name the aquatic animal which has colourless blood but when exposed to oxygen, it turns blue.<p>
								</div>
								
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q1" name="ques1" value="Lobster"/>
										  <label for="q1"><span></span>Lobster</label>
									</li>
									<li>
										<input type="radio" id="q1" name="ques1"  value="Angelfish"/>
										  <label for="q1"><span></span>Angelfish</label>
									</li>
									<li>
										<input type="radio" id="q1" name="ques1"  value="Blue Whale"/>
										  <label for="q1"><span></span>Blue Whale</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>2</div>
								<div class="q-pool">
									<p>Which animal gives birth to four babies at a time and are all the same sex?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q2" name="ques2" value="Elephant"/>
										  <label for="q2"><span></span>Elephant</label>
									</li>
									<li>
										<input type="radio" id="q2" name="ques2" value="Sea horse" />
										  <label for="q2"><span></span>Sea horse</label>
									</li>
									<li>
										<input type="radio" id="q2" name="ques2" value="Armadillo" />
										  <label for="q2"><span></span>Armadillo</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>3</div>
								<div class="q-pool">
								   <p>Which fruit do reindeers like?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q3" name="ques3" value="Apple" />
										  <label for="q3"><span></span>Apple</label>
									</li>
									<li>
										<input type="radio" id="q3" name="ques3" value="Banana" />
										  <label for="q3"><span></span>Banana</label>
									</li>
									<li>
										<input type="radio" id="q3" name="ques3" value="Orange" />
										  <label for="q3"><span></span>Orange</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>4</div>
								<div class="q-pool">
								   <p>Which animal sleeps around 18 hours a day?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q4" name="ques4" value="Koala" />
										  <label for="q4"><span></span>Koala</label>
									</li>
									<li>
										<input type="radio" id="q4" name="ques4" value="Owl" />
										  <label for="q4"><span></span>Owl</label>
									</li>
									<li>
										<input type="radio" id="q4" name="ques4" value="Bat" />
										  <label for="q4"><span></span>Bat</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>5</div>
								<div class="q-pool">
								   <p>A giraffe can clean its ears with tongue. What is the length of the tongue?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q5" name="ques5" value="13 inch" />
										  <label for="q5"><span></span>13 inch</label>
									</li>
									<li>
										<input type="radio" id="q5" name="ques5" value="18 inch" />
										  <label for="q5"><span></span>18 inch</label>
									</li>
									<li>
										<input type="radio" id="q5" name="ques5"  value="21 inch"/>
										  <label for="q5"><span></span>21 inch</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>6</div>
								<div class="q-pool">
								   <p>How many teeth do a bear has?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q6" name="ques6" value="32" />
										  <label for="q6"><span></span>32</label>
									</li>
									<li>
										<input type="radio" id="q6" name="ques6" value="40" />
										  <label for="q6"><span></span>40</label>
									</li>
									<li>
										<input type="radio" id="q6" name="ques6" value="42" />
										  <label for="q6"><span></span>42</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>7</div>
								<div class="q-pool">
								   <p>Lipsticks contain the scales of which animal?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q7" name="ques7" value="Fish" />
										  <label for="q7"><span></span>Fish</label>
									</li>
									<li>
										<input type="radio" id="q7" name="ques7" value="Crocodile" />
										  <label for="q7"><span></span>Crocodile</label>
									</li>
									<li>
										<input type="radio" id="q7" name="ques7" value="Whale" />
										  <label for="q7"><span></span>Whale</label>
									</li>
								</ul>
							</div>
						</div>
				
				<input type="hidden" name="resultWildlifeQuiz" value="resultWildlifeQuiz" id="resultWildlifeQuizId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="wildlifeResult(wildlifeQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->




<script>
	function wildlifeResult(form) {
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
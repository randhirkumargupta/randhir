<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 365px;top:28px;}

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

	<div class="q-header"><h3>DANCE & MUSIC</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">How passionate are you about dance and music?</h2>
		<div class="left-quiz-section">
	    	<form name="dancemusicQuizForm" action="quiz-result.jsp" method="post" id="dancemusicQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>1</div>
						<div class="q-pool">
							<p>Nautanki is a drama form of which North Indian state?<p>
						</div>

						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Delhi"/>
								  <label for="q1"><span></span>Delhi</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Haryana"/>
								  <label for="q1"><span></span>Haryana</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Uttar Pradesh"/>
								  <label for="q1"><span></span>Uttar Pradesh</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>On which instrument does the Lavani dancer dance?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="Dholki"/>
								  <label for="q2"><span></span>Dholki</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Dafli" />
								  <label for="q2"><span></span>Dafli</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Ghungroo" />
								  <label for="q2"><span></span>Ghungroo</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Other than Bhangra, which is the folk dance of Punjab?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Dhap" />
								  <label for="q3"><span></span>Dhap</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Maanch" />
								  <label for="q3"><span></span>Maanch</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Dandass" />
								  <label for="q3"><span></span>Dandass</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Ghumra is a dance form of which state?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Kerala" />
								  <label for="q4"><span></span>Kerala</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Odisha" />
								  <label for="q4"><span></span>Odisha</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Tamil Nadu" />
								  <label for="q4"><span></span>Tamil Nadu</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>Ghazal is a song of?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="Love" />
								  <label for="q5"><span></span>Love</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="Despair" />
								  <label for="q5"><span></span>Despair</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="Separation"/>
								  <label for="q5"><span></span>Separation</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>How many frets does Sitar have?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="24" />
								  <label for="q6"><span></span>24</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="None" />
								  <label for="q6"><span></span>None</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="20" />
								  <label for="q6"><span></span>20</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Bihugeet is a folk music of which state?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Sikkim" />
								  <label for="q7"><span></span>Sikkim</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Nagaland" />
								  <label for="q7"><span></span>Nagaland</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Assam" />
								  <label for="q7"><span></span>Assam</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultDancemusicQuiz" value="resultDancemusicQuiz" id="resultDancemusicQuizId"/>

				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="dancemusicQuizResult(dancemusicQuizForm);"/>
				</div>
			</form>
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->
<script>
	function dancemusicQuizResult(form) {
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
		document.getElementById("resultDancemusicQuizId").value = result;
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

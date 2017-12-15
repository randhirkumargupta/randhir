<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 376px;top:28px;}

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

	<div class="q-header"><h3>BRAND WAR</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Guess these brands from their taglines</h2>
		<div class="left-quiz-section">
	    	<form name="brandQuizForm" action="quiz-result.jsp" method="post" id="brandQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>1</div>
						<div class="q-pool">
							<p>The Ultimate Driving Machine.<p>
						</div>

						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Porsche"/>
								  <label for="q1"><span></span>Porsche</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="BMW"/>
								  <label for="q1"><span></span>BMW</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Lamborghini"/>
								  <label for="q1"><span></span>Lamborghini</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Between love and madness lies obsession.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="Calvin Klein"/>
								  <label for="q2"><span></span>Calvin Klein</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Tommy Hilfiger" />
								  <label for="q2"><span></span>Tommy Hilfiger</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Park Avenue" />
								  <label for="q2"><span></span>Park Avenue</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Innovation delivered.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Apple" />
								  <label for="q3"><span></span>Apple</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Intel" />
								  <label for="q3"><span></span>Intel</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Accenture" />
								  <label for="q3"><span></span>Accenture</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Success. It's a mind game.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Marks & Spencer" />
								  <label for="q4"><span></span>Marks & Spencer</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Tag Heuer" />
								  <label for="q4"><span></span>Tag Heuer</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Coco Chanel" />
								  <label for="q4"><span></span>Coco Chanel</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>You press the button and we do the rest.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="Nikon" />
								  <label for="q5"><span></span>Nikon</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="Kodak" />
								  <label for="q5"><span></span>Kodak</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="Sony"/>
								  <label for="q5"><span></span>Sony</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Tough Guys, dress easy.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Bull" />
								  <label for="q6"><span></span>Bull</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Lion" />
								  <label for="q6"><span></span>Lion</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Crocodile" />
								  <label for="q6"><span></span>Crocodile</label>
							</li>
						</ul>
					</div>
				</div>

				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Quality is remembered long after the price is forgotten.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Gucci" />
								  <label for="q7"><span></span>Gucci</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Reid and Taylor" />
								  <label for="q7"><span></span>Reid and Taylor</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="AKAI" />
								  <label for="q7"><span></span>AKAI</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultBrandQuiz" value="resultBrandQuiz" id="resultBrandQuizId"/>

				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="brandResult(brandQuizForm);"/>
				</div>
			</form>
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->
<script>
	function brandResult(form) {
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
		document.getElementById("resultBrandQuizId").value = result;
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

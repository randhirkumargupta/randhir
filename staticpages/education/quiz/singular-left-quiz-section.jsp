<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 350px;top:28px;}
	
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

	<div class="q-header"><h3>SINGULAR PLURAL</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Do you have brain or brains?</h2>
		<div class="left-quiz-section">
	    	<form name="singularQuizForm" action="quiz-result.jsp" method="post" id="singularQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>1</div>
						<div class="q-pool">
							<p>Singular of Bacteria?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="bacterie"/>
								  <label for="q1"><span></span>bacterie</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="bacterium"/>
								  <label for="q1"><span></span>bacterium</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="bacterius"/>
								  <label for="q1"><span></span>bacterius</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Plural of focus?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="focuses"/>
								  <label for="q2"><span></span>focuses</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="foci" />
								  <label for="q2"><span></span>foci</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="focusys" />
								  <label for="q2"><span></span>focusys</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Which is singular and plural respectively?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="hippopotamus hippopotami" />
								  <label for="q3"><span></span>hippopotamus hippopotami</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="hippopotami hippopotamus" />
								  <label for="q3"><span></span>hippopotami hippopotamus</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="hippopotamus hippopotamuses" />
								  <label for="q3"><span></span>hippopotamus hippopotamuses</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Plural of person?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="many person" />
								  <label for="q4"><span></span>many person</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="persons" />
								  <label for="q4"><span></span>persons</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="people" />
								  <label for="q4"><span></span>people</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>Plural of memo?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="memoes" />
								  <label for="q5"><span></span>memoes</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="memos" />
								  <label for="q5"><span></span>memos</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="memou"/>
								  <label for="q5"><span></span>memou</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Which of these words are same in both singular and plural?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="premises" />
								  <label for="q6"><span></span>premises</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="tableau" />
								  <label for="q6"><span></span>tableau</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="scissors" />
								  <label for="q6"><span></span>scissors</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>'The number of' is followed by a ______ verb?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="plural" />
								  <label for="q7"><span></span>plural</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Singular" />
								  <label for="q7"><span></span>Singular</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="uncountable" />
								  <label for="q7"><span></span>uncountable</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultSingularQuiz" value="resultSingularQuiz" id="resultSingularQuizId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="singularQuizResult(singularQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->
<script>
	function singularQuizResult(form) {
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
		document.getElementById("resultSingularQuizId").value = result;
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
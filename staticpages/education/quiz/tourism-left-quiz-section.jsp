<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 388px;top:28px;}
	
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
	<div class="q-header"><h3>TOURISM</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Dare you to answer what is where in India?</h2>
		<div class="left-quiz-section">
	    	<form name="tourismQuizForm" action="quiz-result.jsp" method="post" id="tourismQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						
						<div class="q-box"><strong>Q</strong>1</div>
						
						<div class="q-pool">
							<p>Which one of the Seven Wonders of the World is located in India?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Taj Mahal"/>
								  <label for="q1"><span></span>Taj Mahal</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Colosseum"/>
								  <label for="q1"><span></span>Colosseum</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Machu Picchu"/>
								  <label for="q1"><span></span>Machu Picchu</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Which city is known as the Silicon Valley of India?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="Hyderabad"/>
								  <label for="q2"><span></span>Hyderabad</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Chennai" />
								  <label for="q2"><span></span>Chennai</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Bangalore" />
								  <label for="q2"><span></span>Bangalore</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Where is Gateway of India located?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Delhi" />
								  <label for="q3"><span></span>Delhi</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Mumbai" />
								  <label for="q3"><span></span>Mumbai</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Kolkata" />
								  <label for="q3"><span></span>Kolkata</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Which is the longest river in India?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Ganga" />
								  <label for="q4"><span></span>Ganga</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Indus" />
								  <label for="q4"><span></span>Indus</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Godavari" />
								  <label for="q4"><span></span>Godavari</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>Which city is known as the "Pink City" in India?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="Jaipur" />
								  <label for="q5"><span></span>Jaipur</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="Udaipur" />
								  <label for="q5"><span></span>Udaipur</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="Haridwar"/>
								  <label for="q5"><span></span>Haridwar</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Which Indian hill station is known as the "Queen of Hills"?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Shimla" />
								  <label for="q6"><span></span>Shimla</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Darjeeling" />
								  <label for="q6"><span></span>Darjeeling</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Mussoorie" />
								  <label for="q6"><span></span>Mussoorie</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>After how many years does Kumbha Mela takes place?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="12" />
								  <label for="q7"><span></span>12</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="8" />
								  <label for="q7"><span></span>8</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="4" />
								  <label for="q7"><span></span>4</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultTourismQuiz" value="resultTourismQuiz" id="resultTourismQuizId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="tourismResult(tourismQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->




<script>
	function tourismResult(form) {
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
		document.getElementById("resultTourismQuizId").value = result;
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
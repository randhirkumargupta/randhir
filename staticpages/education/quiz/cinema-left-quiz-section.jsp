<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat; width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 388px;top:28px;}
	
	.left-quiz-section{padding:10px;}
	.q-box-section{ width:660px; height:66px; background:#fffde8;}
	.q-box{ width:40px; height:66px; line-height:66px; background:#f86e6c; text-align:center; color:#FFFFFF; float:left;}
	.q-box strong{ font-size:22px; font-weight:normal;}
	.q-pool {width: 580px;height: 66px;font-size: 16px;color: #9d9b9e;margin-left: 20px;float: left;}
	.radio-button-box{margin-left:40px;}
	.radio-button-box li{ list-style:none; float:left; margin-right:60px;padding: 18px 15px;}

	.active{ background: #fffde8;padding: 18px 15px;-moz-border-radius: 0px 0px 10px 10px; -webkit-border-radius: 0px 0px 10px 10px; border-radius: 0px 0px 10px 10px;
		/*IE 7 AND 8 DO NOT SUPPORT BORDER RADIUS*/
	}
	.question-box{width: 675px;margin-bottom: 50px;float: left;}
	.styledRadio{  float:left; margin-right:5px; outline:0;}
	.radio-button-box label{ font-size:16px; color:#9d9b9e}
	.quiz-button{ width:675px; text-align:center; margin-top:20px;}
</style>

<div id="left-quiz-section">
	<div class="q-header"><h3>Indian Cinema</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Are you a Bollywood buff?</h2>
		<div class="left-quiz-section">
	    	<form name="cinemaQuizForm" action="quiz-result.jsp" method="post" id="cinemaQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						
						<div class="q-box"><strong>Q</strong>1</div>
						
						<div class="q-pool">
							<p>Filmfare awards were started from the year?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="1952"/>
								  <label for="q1"><span></span>1952</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="1964"/>
								  <label for="q1"><span></span>1964</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="1954"/>
								  <label for="q1"><span></span>1954</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Shivaji Rao Gaikwad is the real name of which actor?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="NTR"/>
								  <label for="q2"><span></span>NTR</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Chiranjeevi" />
								  <label for="q2"><span></span>Chiranjeevi</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Rajnikanth" />
								  <label for="q2"><span></span>Rajnikanth</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Which famous personality of Bollywood was born as Balraj Dutt?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Utpal" />
								  <label for="q3"><span></span>Utpal Dutt</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Guru" />
								  <label for="q3"><span></span>Guru Dutt</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Sunil" />
								  <label for="q3"><span></span>Sunil Dutt</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Ravi Kapoor's other name in Bollywood is?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Dharmendra" />
								  <label for="q4"><span></span>Dharmendra</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Jeetendra" />
								  <label for="q4"><span></span>Jeetendra</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Vinod Khanna" />
								  <label for="q4"><span></span>Vinod Khanna</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>Which was considered as India's largest and most influential film companies of the silent era?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="Hindustan" />
								  <label for="q5"><span></span>Hindustan Cinema</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="Bombay" />
								  <label for="q5"><span></span>Bombay Talkies</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="Kohinoor"/>
								  <label for="q5"><span></span>Kohinoor Film Company</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Who was the original hero who was replaced after his death by Dilip Kumar in K. Asif's famous Hindi blockbuster 'Mughal-e-Azam'?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="P.C." />
								  <label for="q6"><span></span>P.C. Barua</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="BB" />
								  <label for="q6"><span></span>Bharat Bhushan</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Chandra" />
								  <label for="q6"><span></span>Chandra Mohan</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Which famous director scored two hat-tricks by winning the Filmfare 'Best Director' Award for the years 1953, 1954, 1955 and 1958, 1959 and 1960?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Bimal" />
								  <label for="q7"><span></span>Bimal Roy</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Mehboob" />
								  <label for="q7"><span></span>Mehboob Khan</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Prithviraj" />
								  <label for="q7"><span></span>Prithviraj Kapoor</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>8</div>
						<div class="q-pool">
						   <p>The first Dada Saheb Phalke award is won by?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q8" name="ques8" value="Devika" />
								  <label for="q8"><span></span>Devika Rani</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="Dileep" />
								  <label for="q8"><span></span>Dileep Kumar</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="Jatin" />
								  <label for="q8"><span></span>Jatin Lalit</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>9</div>
						<div class="q-pool">
						   <p>Music Director R.D. Burman is also known as _____________.</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q9" name="ques9" value="Rocky" />
								  <label for="q9"><span></span>Rocky</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Pancham" />
								  <label for="q9"><span></span>Pancham</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Chintu" />
								  <label for="q9"><span></span>Chintu</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>10</div>
						<div class="q-pool">
						   <p>Which Indian actor is known as 'Tragedy King'?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q10" name="ques10" value="Dilip" />
								  <label for="q10"><span></span>Dilip Kumar</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="Amitabh" />
								  <label for="q10"><span></span>Amitabh Bachan</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="Sanjeev" />
								  <label for="q10"><span></span>Sanjeev Kumar</label>
							</li>							
						</ul>
					</div>
				</div>								
				<input type="hidden" name="resultCinema" value="resultCinema" id="resultCinemaQuizId"/>
				<input type="hidden" name="cinemaQuiz10ques" value="10ques"/>				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="tourismResult(cinemaQuizForm);"/>
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
		for(index = 0; index < form.ques8.length; index++) {
			if(form.ques8[index].checked)
				result = result + "#" + "q8-" + form.ques8[index].value;
		}
		for(index = 0; index < form.ques9.length; index++) {
			if(form.ques9[index].checked)
				result = result + "#" + "q9-" + form.ques9[index].value;
		}
		for(index = 0; index < form.ques10.length; index++) {
			if(form.ques10[index].checked)
				result = result + "#" + "q10-" + form.ques10[index].value;
		}
		document.getElementById("resultCinemaQuizId").value = result;
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
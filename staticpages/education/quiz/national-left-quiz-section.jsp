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
	<div class="q-header"><h3>National</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Quiz on Republic Day</h2>
		<div class="left-quiz-section">
	    	<form name="nationalQuizForm" action="quiz-result.jsp" method="post" id="nationalQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						
						<div class="q-box"><strong>Q</strong>1</div>
						
						<div class="q-pool">
							<p>Which country has the largest Constitution in the World?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="USA"/>
								  <label for="q1"><span></span>United States of America</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="India"/>
								  <label for="q1"><span></span>India</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="AUS"/>
								  <label for="q1"><span></span>Australia</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="China"/>
								  <label for="q1"><span></span>China</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>How many articles are there in Indian constitution?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="400"/>
								  <label for="q2"><span></span>400</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="392" />
								  <label for="q2"><span></span>392</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="467" />
								  <label for="q2"><span></span>467</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="444" />
								  <label for="q2"><span></span>444</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Who is the speaker of the Lok Sabha?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Sumitra" />
								  <label for="q3"><span></span>Sumitra Mahajan</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Meira" />
								  <label for="q3"><span></span>Meira Kumar</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Sushma" />
								  <label for="q3"><span></span>Sushma Swaraj</label>
							</li>
														<li>
								<input type="radio" id="q3" name="ques3" value="Meenakshi" />
								  <label for="q3"><span></span>Meenakshi Lekhi</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Who signs bills to become laws, in India?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="TPM" />
								  <label for="q4"><span></span>The Prime Minister</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="TP" />
								  <label for="q4"><span></span>The President</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="TSLS" />
								  <label for="q4"><span></span>The Speaker of the Lok Sabha</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="HM" />
								  <label for="q4"><span></span>Home Minister</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>How many spokes does Indian flag have?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="16" />
								  <label for="q5"><span></span>16</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="31" />
								  <label for="q5"><span></span>31</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="24"/>
								  <label for="q5"><span></span>24</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="26"/>
								  <label for="q5"><span></span>26</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Who is known as the Chief architect of Indian Constitution?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Jawaharlal" />
								  <label for="q6"><span></span>Jawaharlal Nehru</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Mahatma" />
								  <label for="q6"><span></span>Mahatma Gandhi</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Ambedkar" />
								  <label for="q6"><span></span>Dr. B. R. Ambedkar</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Rajendra" />
								  <label for="q6"><span></span>Rajendra Prasad</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Why can't Rajya Sabha discuss the budget?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="250Members" />
								  <label for="q7"><span></span>Because Rajya Sabha is limited to a number of 250 members</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="HouseOfCommons" />
								  <label for="q7"><span></span>Because Rajya Sabha is not the House of Commons</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="ProtectsTheRights" />
								  <label for="q7"><span></span>Because Rajya Sabha protects the Rights of States against the Union</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="NoConfidence" />
								  <label for="q7"><span></span>Because Rajya Sabha cannot  bring the motion of no confidence</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>8</div>
						<div class="q-pool">
						   <p>The total number of Union Territories in India are?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q8" name="ques8" value="11" />
								  <label for="q8"><span></span>11</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="9" />
								  <label for="q8"><span></span>9</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="10" />
								  <label for="q8"><span></span>10</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="Seven" />
								  <label for="q8"><span></span>7</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>9</div>
						<div class="q-pool">
						   <p>Which of these is not a Fundamental Right?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q9" name="ques9" value="Right2Life" />
								  <label for="q9"><span></span>Right to Life</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Right2Privacy" />
								  <label for="q9"><span></span>Right to Privacy</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Right2Constitutional" />
								  <label for="q9"><span></span>Right to Constitutional Remedies</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Right2Exploitation" />
								  <label for="q9"><span></span>Right to exploitation </label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>10</div>
						<div class="q-pool">
						   <p>Which is the capital of Telangana?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q10" name="ques10" value="HYD" />
								  <label for="q10"><span></span>Hyderabad</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="Chennai" />
								  <label for="q10"><span></span>Chennai</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="Amravati" />
								  <label for="q10"><span></span>Amravati</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="Coimbatore" />
								  <label for="q10"><span></span>Coimbatore </label>
							</li>							
						</ul>
					</div>
				</div>								
				<input type="hidden" name="resultNational" value="resultNational" id="resultNationalQuizId"/>
				<input type="hidden" name="nationQuiz10ques" value="10ques"/>				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="tourismResult(nationalQuizForm);"/>
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
		document.getElementById("resultNationalQuizId").value = result;
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
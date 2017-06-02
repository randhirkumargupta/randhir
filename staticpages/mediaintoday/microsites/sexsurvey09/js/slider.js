var p = 7;
var cnt = 0;
var s=0;
var t=0;
var h;
var arrlength = new Array();
arrlength[0] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202120121_Fantasies1.jpg';
arrlength[1] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202115322_Faithfullyyours1.jpg';
arrlength[2] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202120121_Fetishes1.jpg';
arrlength[3] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202120121_Peoplepleasures.jpg';
arrlength[4] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202115322_Wanderlust1.jpg';

arrlength[5] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202115322_Voyeursatwork1.jpg';
arrlength[6] = '/staticpages/mediaintoday/indiatoday//images/stories/Sexsurvey09/091202115322_Pornography.jpg';





var arrtext = new Array();
arrtext[0] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72490/Cover%20Story/Mind+games.html' target='_blank'>Mind games: </a></b>Urban Indians emerge as cautious tourists, not fearless adventurers, in a new universe of fantasy. The technology of fantasy has expanded dramatically, allowing urban Indians access to a supermarket of choices, but all it has done is expand information, not intimacy. Relationships are less conversation, more convenience; less playgrounds, more prisons. <b><a href='http://indiatoday.intoday.in/site/Story/72490/Cover%20Story/Mind+games.html' target='_blank'>Read Story</a></b> ";
arrtext[1] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72494/Cover%20Story/The+marriage+trap.html' target='_blank'>The marriage trap: </a></b>A nation's imagination is different from its actuality. Despite an increasingly electric image of the marital bed, physical pleasure seems to be an infrequent visitor. With deep sexual unhappiness in urban middle-class India, yes, it is the right time to imagine, to re-imagine, a marriage with sexy spaces together, not alone.  <b><a href='http://indiatoday.intoday.in/site/Story/72494/Cover%20Story/The+marriage+trap.html' target='_blank'>Read Story</a></b>";
arrtext[2] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72495/Cover%20Story/Special+effects.html' target='_blank'>Special effects: </a></b>Once aberrant, now open to discussion. Once perverse, now being practised. If sex as leisure is becoming acceptable, so are its accessories. The idea of fetish has an interesting lineage. It is both a product of European engagements with 'primitive' cultures that existed beyond Europe's borders, as well as 'irrational' thinking that, apparently, proliferated within them. <b><a href='http://indiatoday.intoday.in/site/Story/72495/Cover%20Story/Special+effects.html' target='_blank'>Read Story</a></b>";
arrtext[3] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72497/Cover%20Story/Objects+of+desire.html' target='_blank'>Objects of desire: </a></b>Do women want to act out their fantasies? No. The safe sex thought police, it seems, has taken over the female moral universe. Young women are being asked that they walk the thin and invisible line that demands that they appear sexually desirable without earning the label slut, and that they remain essentially virtuous Indian women without becoming frumpy aunties. <b><a href='http://indiatoday.intoday.in/site/Story/72497/Cover%20Story/Objects+of+desire.html' target='_blank'>Read Story</a></b>";
arrtext[4] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72503/Cover%20Story/Comfort+zones.html' target='_blank'>Comfort zones: </a></b>The eroticism of the ordinary triumphs in the urban Indian's sexual imagination, crowded out by cramped homes and dangerous public spaces. A person's sexuality is by no means a private affair but rather a public good. It is generated in different contexts, depending on social status, education, economic capital, on lifestyle aspirations and a host of heterogeneous moral universes. <b><a href='http://indiatoday.intoday.in/site/Story/72503/Cover%20Story/Comfort+zones.html' target='_blank'>Read Story</a></b>";

arrtext[5] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72500/Cover%20Story/Show+and+tell.html' target='_blank'>Show and tell: </a></b>Voyeurism and exhibitionism have found a happy hunting ground in India, it appears. A chimeral anxiety, however, shadows the liberatory, celebratory aura emanating from sexual excess and success. The questions on voyeurism/exhibitionism framed for the sex survey of 2009 reflect our new-found obsession with the camera and its immense foucauldian (fuckauldian?) grip on our sexual imaginations. <b><a href='http://indiatoday.intoday.in/site/Story/72500/Cover%20Story/Show+and+tell.html' target='_blank'>Read Story</a></b>";
arrtext[6] = "<b class='scrollblueboldtext'><a href='http://indiatoday.intoday.in/site/Story/72501/Cover%20Story/Out+of+the+box.html' target='_blank'>Out of the box: </a></b>The squeamishness about pornography as couples therapy is an offshoot of the belief that sex is purely for reproduction not pleasure. Vatsyayana, India's oldest sexologist, would not have been happy. If just the portrayal of prostitution or sex makes pornography socially deplorable, then we'd have to rebuff or destroy a good deal of Indian artefacts and literature. <b><a href='http://indiatoday.intoday.in/site/Story/72501/Cover%20Story/Out+of+the+box.html' target='_blank'>Read Story</a></b>";








var q = p*3;

function vshow(c)
{
if(c=='n')
  
 {
	 s=s%p;
 cnt=cnt+1;
 s=cnt;
 t=cnt*3;
s=s%p;
for(cnt=s; cnt<=s && cnt<p; cnt++)
 {document.i1.src=arrlength[cnt%p];
 document.getElementById("text1").innerHTML=arrtext[cnt%p];
 
 t=t+3;
 t=t%q;
break;
}
 } 
  
 else 
{
s=s%p;
s=cnt-1;
if(s<0)
{
	if(s == -2)
		s=p-2;
	else
		s=p-1;
}
s=s%p;
 
   t=t-1;
   if(t<0)
   {t=q-1}
   t=t%q;
   
  for(cnt=s; cnt>=s && cnt<p; cnt--)
  {
     document.i1.src=arrlength[(cnt+p)%p];
 document.getElementById("text1").innerHTML=arrtext[(cnt+p)%p];
  t=t-2;
  break;
 }
}
}

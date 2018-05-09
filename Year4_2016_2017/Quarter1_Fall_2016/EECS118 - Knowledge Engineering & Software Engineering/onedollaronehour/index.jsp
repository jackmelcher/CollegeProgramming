<! Jack Melcher
	 67574625
	 10/27/2016
	 EECS118
	 Term Project
>

<%-- In the beginning of the file, import the library you need: --%>
<%@ page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.util.*"%>
<%@ page import="java.io.*"%>
<%@ page import="java.text.NumberFormat"%>

<!jsoup libraries for html parsing/cleaning>
<%@ page import="org.jsoup.*"%>
<%@ page import="org.jsoup.helper.*"%>
<%@ page import="org.jsoup.nodes.*"%>
<%@ page import="org.jsoup.parser.*"%>
<%@ page import="org.jsoup.safety.*"%>
<%@ page import="org.jsoup.select.*"%>

<html>
	<head>
		<title>One Dollar One Hour</title>
		<style>
		table, th, td {
			border: 1px solid black;
			border-collapse: collapse;
		}
		</style>
	</head>
  
  
	<body>

		<h1>One Dollar One Hour!!!</h1>

		<!User provides keywords of a video game's title. When the search button is pressed, a list of video games containing the keywords should pop-up >

		<br>

		<!Function A>
		<b>Search for a Game</b>
		<form method="post">
			<input name="queryString" type=text/>
			<input type="submit" name="submit1" value="Search"/>
		</form>
		<%
		if (request.getParameter("submit1") != null) {
			Document doc;
			
			//for(int i=1; i<=1293; i++){

			try {

				// need http protocol
				doc = Jsoup.connect("https://steamspy.com/search.php?s="+request.getParameter("queryString")).userAgent("Mozilla").get();
				//out.println("Connected to the website <br>");

				//Table
				out.println("<table>");
				out.println("<tr>");
				out.println("<th>App ID</th>");
				out.println("<th>Title</th>");
				out.println("<th>Image</th>");
				out.println("</tr>");

				// get page title
				/*
				String title = doc.title();
				out.println("title : " + title+"<br>");
				out.println("<br>");
				*/

				
				// get game titles
				Elements game_titles = doc.select("h3");
				/*
				for (Element game_title : game_titles) {
					// get the value
					out.println("game_title : "+game_title.html()+"<br>");
					out.println("<br>");
				}
				*/
				// get all links
				Elements links = doc.select("a[href*=/app/]");
				/*
				for (Element link : links) {
					// get the value from href attribute
					//out.println("link : <a href=https://steamspy.com"+link.attr("href")+">https://steamspy.com"+link.attr("href")+"</a>"+"<br>");
					out.println(link.attr("href").substring(5));
					out.println("<br>");
				}
				*/

				// get the image
				Elements images = doc.select("img[src$=.jpg]");
				/*
				for (Element image : images) {
					//out.println("image: "+image.attr("src")+"<br>");
					out.println(image.toString());
				}
				*/

				//Print values from both Elements lists
				for(int i = 0; i < game_titles.size(); i++){
					out.println("<tr>");
					out.println("<td><form method=\"post\"><input name=\"submit2\" type=\"submit\" value=\""+links.get(i).attr("href").substring(5)+"\"></form></td>");
					out.println("<td>"+game_titles.get(i).html()+"</td>");
					out.println("<td>"+images.get(i).toString()+"</td>");
					out.println("</tr>");
				}

			out.println("</table>");


			} catch (IOException e) {
				out.println("Threw an error<br>");
				e.printStackTrace();
				out.println(e.getMessage());
			}	
		}
		%>		

		<!When a game is selected by the user from the above list the following with display>
		
		<!Data pulled from the databases>

		<!App ID>

		<!Game Title>

		<!Cover Art>

		<!Steam Store Page>

		<!Average Playtime>

		<!Price>

		<!Ratings (From Metacritic)>


		<!Calculated Values>
		<!OneDollarOneHour Score (Average Playtime - Listed Price)>
		
		<!Dollar per Hour (Price / Average Playtime)>
		
		<!Replay Value (Based on Average Playtime and Number of Concurrent Players)>


		<!Function B>
		<%
		if (request.getParameter("submit2") != null) {
			Document doc;
			

			try {

				// need http protocol
				doc = Jsoup.connect("https://steamspy.com/app/"+request.getParameter("submit2")).userAgent("Mozilla").get();
				//out.println("Connected to the website <br>");
		
				// get game titles
				Elements game_titles = doc.select("h3");
				for (Element game_title : game_titles) {
					// get the value
					out.println(game_title.html()+"<br>");
					out.println("<br>");
				}
				
				// get all links
				/*
				Elements links = doc.select("a[href*=store.steampowered.com/app/"+request.getParameter("submit2")+"]");
				for (Element link : links) {
					// get the value from href attribute
					out.println(link.toString());
					out.println("<br>");
				}
				*/
				out.println("<a href=https://store.steampowered.com/app/"+request.getParameter("submit2")+"> Steam Store</a>"+"<br><br>");

				// get the image
				Elements images = doc.select("img[src*="+request.getParameter("submit2")+"]");
				/*
				for (Element image : images) {
					//display image
					out.println(image.toString());
					out.println("<br>");
				}
				*/
				out.println(images.get(0).toString());
				out.println("<br><br>");

				//Print values from both Elements lists
				String values = doc.select("p").text();
				//String values1 = doc.select("p").outerHtml();
				//String values2 = doc.select("strong ~ br").html();
				//String values3 = doc.select("br ~ strong").html();
				//String values4 = doc.select("br").html();
				//out.println(values);
				//out.println(values1);
				//out.println(values2);
				//out.println(values3);
				//out.println(values4);
				//out.println("<br>");
				//out.println("<br><br>");

				//Pulled Data
				//out.println("Title<br><br>");
				//out.println("Image<br><br>");
				//out.println("Steam Store Page<br><br>");
				//out.println("Average Playtime<br><br>");
				//out.println("Price<br><br>");
				
				//Calculated Data
				//out.println("OneDollarOneHour Score<br><br>");
				//out.println("Dollar per Hour (Average)<br><br>");				
				//out.println("Popularity<br><br>");
				//out.println("Money Earned<br><br>");

				//Acquire everything in p to /p
				//Convert to text
				//Spilt text so that way i can get the right info
				//perform calculations based on info
				//print that to screen as well

				//Pulled Data
				out.println("Pulled Data<br>");
				//Price
				int index = values.indexOf("Price:");
				String pricestring = "";
				//out.println(index);
				int i = 0;
				if(index != -1){
					while(i < 2){
						//out.print(values.charAt(index));
						if(i > 0){
							pricestring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				float price = 0;
				//out.println(pricestring+"<br>");
				//out.println(pricestring.replace('$',' ')+"<br>");
				
				Scanner scanner = new Scanner(pricestring.replace('$',' '));
				if(scanner.hasNextFloat()){
					price = scanner.nextFloat();
				}
				out.println("Price: $"+price+"<br>");


				//Playtime Total
				index = values.indexOf("Playtime total:");
				String averageplaytimestring = "";
				//out.println(index);
				i = 0;
				if(index != -1){
					while(i < 3){
						//out.print(values.charAt(index));
						if(i > 1){
							averageplaytimestring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int averageplaytimehour = 0;
				int averageplaytimemin = 0;
				float averageplaytime = 0;
				//out.println(averageplaytimestring+"<br>");

				scanner = new Scanner(averageplaytimestring.replace(':',' '));
				if(scanner.hasNextInt()){
					averageplaytimehour = scanner.nextInt();
				}
				if(scanner.hasNextInt()){
					averageplaytimemin = scanner.nextInt();
				}
				averageplaytime = averageplaytimehour + ((float)averageplaytimemin/60);
				out.println("Average Playtime Total: "+String.format("%.2f",averageplaytime)+" hours<br>");


				//Playtime last 2 weeks
				index = values.indexOf("Playtime in the last 2 weeks:");
				String averageplaytime2weeksstring = "";
				//out.println(index);
				i = 0;
				if(index != -1){
					while(i < 7){
						//out.print(values.charAt(index));
						if(i > 5){
							averageplaytime2weeksstring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int averageplaytime2weekshour = 0;
				int averageplaytime2weeksmin = 0;
				float averageplaytime2weeks = 0;
				//out.println(averageplaytime2weeksstring+"<br>");

				scanner = new Scanner(averageplaytime2weeksstring.replace(':',' '));
				if(scanner.hasNextInt()){
					averageplaytime2weekshour = scanner.nextInt();
				}
				if(scanner.hasNextInt()){
					averageplaytime2weeksmin = scanner.nextInt();
				}
				averageplaytime2weeks = averageplaytime2weekshour + ((float)averageplaytime2weeksmin/60);
				out.println("Average Playtime in the Last Two Weeks: "+String.format("%.2f",averageplaytime2weeks)+" hours<br>");


				//Metacritic Score
				index = values.indexOf("Metascore:");
				String metascorestring = "";
				//out.println(index);
				i = 0;
				if(index != -1){
					while(i < 2){
						//out.print(values.charAt(index));
						if(i > 0){
							metascorestring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int metascore = 0;
				//out.println(metascorestring+"<br>");

				scanner = new Scanner(metascorestring.replaceAll("%",""));
				if(scanner.hasNextInt()){
					metascore = scanner.nextInt();
				}
				out.println("Meta Score: "+metascore+"%<br>");

				//User Score
				index = values.indexOf("Userscore:");
				String userscorestring = "";
				//out.println(index);
				i = 0;
				if(index != -1){
					while(i < 2){
						//out.print(values.charAt(index));
						if(i > 0){
							userscorestring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int userscore = 0;
				//out.println(userscorestring+"<br>");

				scanner = new Scanner(userscorestring.replaceAll("%",""));
				if(scanner.hasNextInt()){
					userscore = scanner.nextInt();
				}
				out.println("User Score: "+userscore+"<br>");


				//Total Number of Owners
				index = values.indexOf("Owners:");
				String ownersstring = "";
				//out.println(index);
				i = 0;
				if(index != -1){
					while(i < 2){
						//out.print(values.charAt(index));
						if(i > 0){
							ownersstring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int owners = 0;
				//out.println(ownersstring+"<br>");

				scanner = new Scanner(ownersstring.replaceAll(",",""));
				if(scanner.hasNextInt()){
					owners = scanner.nextInt();
				}
				//out.println(owners+"<br>");
				out.println("Owners: "+ownersstring+"<br>");



				//Total Number of Players
				index = values.indexOf("Players total:");
				String playertotalstring = "";
				//out.println(index);
				i = 0;
				if(index != -1){
					while(i < 3){
						//out.print(values.charAt(index));
						if(i > 1){
							playertotalstring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int playerstotal = 0;
				//out.println(playertotalstring+"<br>");

				scanner = new Scanner(playertotalstring.replaceAll(",",""));
				if(scanner.hasNextInt()){
					playerstotal = scanner.nextInt();
				}
				//out.println(playerstotal+"<br>");
				out.println("Players: "+playertotalstring+"<br>");


				//Players in last 2 weeks
				index = values.indexOf("Players in the last 2 weeks:");
				String players2weeksstring = "";
				//out.println(averageplaytimeindex);
				i = 0;
				if(index != -1){
					while(i < 7){
						//out.print(values.charAt(index));
						if(i > 5){
							players2weeksstring += values.charAt(index);
						}
						index++;
						if(values.charAt(index) == ' '){
							i++;
						}
					}
					//out.println("<br>");
				}
				int players2weeks = 0;
				//out.println(players2weeksstring+"<br>");

				scanner = new Scanner(players2weeksstring.replaceAll(",",""));
				if(scanner.hasNextInt()){
					players2weeks = scanner.nextInt();
				}
				//out.println(players2weeks+"<br>");
				out.println("Players in the Last Two Weeks: "+players2weeksstring+"<br>");

				out.println("<br>");
				out.println("Calculated Data<br>");

				//Calculated Data
				float oneDollarOneHourScore = averageplaytime - price;
				float dollarPerHour = price / averageplaytime;
				float estimatedProfit = price * owners;
				float activeplayerrate = (float)players2weeks / (float)playerstotal * 100;
				float averageplaysession = averageplaytime2weeks / 14;
				float overallrating = (metascore + userscore) / 2;
				float playerpercent =  (float)playerstotal /  (float)owners *100;

				if(oneDollarOneHourScore > 0){
					out.println("One Dollar One Hour Score: +"+String.format("%.2f",oneDollarOneHourScore)+"<br>");
				}
				else{
					out.println("One Dollar One Hour Score: "+String.format("%.2f",oneDollarOneHourScore)+"<br>");
				}
				
				if(dollarPerHour != 0){
					out.println("Dollar Per Hour: $"+String.format("%.2f",dollarPerHour)+"/hour<br>");
				}
				else{
					out.println("Dollar Per Hour: Infinite!<br>");
				}
				
				if(estimatedProfit != 0){
					//out.println("Estimated Profit: "+String.format("%.0f",estimatedProfit)+"<br>");
					out.println("Estimated Profit: $"+NumberFormat.getNumberInstance(Locale.US).format(estimatedProfit)+"<br>");
				}
				else{
					out.println("Estimated Profit: None...<br>");
				}

				out.println("Active Player Percentage: "+String.format("%.2f",activeplayerrate)+"%<br>");
				
				out.println("Average Play Session: "+String.format("%.2f",averageplaysession)+" hours/day<br>");

				if(metascore != 0 && userscore != 0){
					out.println("Overall Score: "+overallrating+"%<br>");
				}

				out.println("Player to Owner Percentage: "+String.format("%.2f",playerpercent)+"%<br>");

				out.println("Current Activity: ");
				if(players2weeks >= 2000000) {
					out.println("Very High<br>");
				}
				else if(players2weeks >= 1000000) {
					out.println("Very High<br>");
				}
				else if(players2weeks >= 500000) {
					out.println("High<br>");
				}
				else if(players2weeks >= 250000) {
					out.println("Moderately High<br>");
				}
				else if(players2weeks >= 100000) {
					out.println("Moderately<br>");
				}
				else if(players2weeks >= 10000) {
					out.println("Moderate<br>");
				}
				else if(players2weeks >= 1000) {
					out.println("Low<br>");
				}
				else if(players2weeks >= 0) {
					out.println("Very Low<br>");
				}
				else if(players2weeks == 0) {
					out.println("Abandoned<br>");
				}

				out.println("Worth the Price? ");
				if(oneDollarOneHourScore >= 100) {
					out.println("Unquestionably<br>");
				}
				else if(oneDollarOneHourScore >= 75) {
					out.println("Truely<br>");
				}
				else if(oneDollarOneHourScore >= 50) {
					out.println("Absolutely<br>");
				}
				else if(oneDollarOneHourScore >= 25) {
					out.println("Definitely<br>");
				}
				else if(oneDollarOneHourScore >= 0) {
					out.println("Yes<br>");
				}
				else if(oneDollarOneHourScore >= -10) {
					out.println("Almost<br>");
				}
				else if(oneDollarOneHourScore >= -20) {
					out.println("Questionable<br>");
				}
				else if(oneDollarOneHourScore >= -30) {
					out.println("No<br>");
				}
				else if(oneDollarOneHourScore >= -40) {
					out.println("Spend your money elsewhere<br>");
				}

				

			} catch (IOException e) {
				out.println("Threw an error<br>");
				e.printStackTrace();
				out.println(e.getMessage());
			}

			out.println("<br><br>");
		}
		%>		




		<!When a game is selected by the user from the above list the following with display>
		
		<!Data pulled from the databases>
		<!Cover Art>

		<!Average Playtime>
		<b>Average Playtime</b><br><br>

		<!Price>
		<b>Current Listed Price</b><br><br>

		<!Ratings (From Metacritic)>
		<b>Meta Score</b><br><br>
		<b>User Score</b><br><br>

		<!Calculated Values>
		<!OneDollarOneHour Score (Average Playtime - Listed Price)>
		<b>OneDollarOneHour Score</b><br><br>
		
		<!Dollar per Hour (Price / Average Playtime)>
		<b>Dollar per Hour</b><br><br>
		
		<!Replay Value (Based on Average Playtime and Number of Concurrent Players)>
		<b>Replay Value</b><br><br>
		
		<br><br>



		<!When a game is selected by the user from the above list the following with display>
		
		<!Data pulled from the databases>
		<!Cover Art>

		<!User Playtime>
		<b>User Playtime</b><br><br>

		<!Price>
		<b>Current Listed Price</b><br><br>

		<!Ratings (From Metacritic)>
		<b>Meta Score</b><br><br>
		<b>User Score</b><br><br>

		<!Calculated Values>
		<!OneDollarOneHour Score (User Playtime - Listed Price)>
		<b>OneDollarOneHour Score</b><br><br>
		
		<!Dollar per Hour (Price / Average Playtime)>
		<b>Dollar per Hour</b><br><br>
		
		<!Time Remaining to achieve 1Dollar1Hour>
		<b>Time to 1Dollar1Hour</b><br><br>
	

	</body>
</html>








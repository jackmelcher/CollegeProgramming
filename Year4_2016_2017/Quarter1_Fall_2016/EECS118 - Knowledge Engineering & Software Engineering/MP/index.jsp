<%-- Jack Melcher
	 67574625
	 10/9/2016
	 EECS118 MP2
--%>

<%-- In the beginning of the file, import the library you need: --%>
<%@ page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.util.*"%>
<%@ page import="java.io.*" %>
<%@ page import="java.sql.*"%>
<%	String funcID = request.getParameter(“funcID”);
	String name = request.getParameter(“name”);
<%-- ... --%>
%>

<%-- request.getParameter() can get the attributes submitted by the form you define: --%>
<form method="post">
	<input name="funcID" type="hidden" value="2">
	Customer name: <input name="name" type="text">
	Street: <input name="street" type="text">
	City: <input name="city" type="text">
	<input type="submit" value="Add"/>
</form>

<%-- To Load the SQL driver: --%>
try {
	Class.forName("com.mysql.jdbc.Driver").newInstance();
}
catch(Exception e) {
	out.println("can't load mysql driver");
	out.println(e.toString());
}

<%-- To Create a Connection with MySQL Server for the database “bank”: --%>
String url="jdbc:mysql://127.0.0.1:3306/gallery";
	String id="gallery";
	String pwd="eecs118";
	Connection con= DriverManager.getConnection(url,id,pwd);

<%-- To Perform SQL Queries: --%>
stmt = con.createStatement();
String sql="SELECT * FROM customer";
rs=stmt.executeQuery(sql);
<%-- ... --%>
while (rs.next()) {
	out.println("<tr>");
	out.println("<td>"+rs.getString("customer_id")+"</td>");
	out.println("<td>"+rs.getString("customer_name")+"</td>");
	out.println("<td>"+rs.getString("customer_street")+"</td>");
	out.println("<td>"+rs.getString("customer_city")+"</td>");
	out.println("</tr>");
}


<%--
	Use executeQuery() to query the data from the table.
	Use rs.getString(“Attribute”) to get the value of the attribute from a tuple.
	Out.println() can write the content back to the webpage HTML.
 --%>

<%-- To Add a Tuple into a Table: --%>
pstmt = con.prepareStatement("insert into customer values
(default,?,?,?)",Statement.RETURN_GENERATED_KEYS);
pstmt.clearParameters();
pstmt.setString(1, name);
pstmt.setString(2, street);
pstmt.setString(3, city);
pstmt.executeUpdate();
rs=pstmt.getGeneratedKeys();
while (rs.next()) {
	out.println("Successfully added. Customer_ID:"+rs.getInt(1));
}

<%-- 
Note that:
- PreparedStatements can use variables and are more efficient.
- “default” means to use the default value for customer_ID, which should be auto
	incremented.
- “Statement.RETURN_GENERATED_KEYS” means you want to know the
	auto-generated customer_ID after insertion.
- Use executeUpdate() to perform any modification to the data, e.g., insert, delete.
- Use re.getInt(1) to obtain the first attribute from the result (with type Integer),
	which should be the customer_ID generated.
--%>
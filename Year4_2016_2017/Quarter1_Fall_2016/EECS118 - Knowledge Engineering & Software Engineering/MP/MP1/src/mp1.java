// Jack Melcher
// SID: 67574625
// 10/1/2016
// EECS 118
// MiniProject 1

import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.Statement;

public class mp1 {
    Connection conn;//connection to database	
	
	public mp1(){
	// build a default connection to database
		String driver = "com.mysql.jdbc.Driver";
        String url = "jdbc:mysql://128.195.204.85:3306/mp1";
        String user = "eecs118";
        String password = "miniproject2";  
       
        try {
            Class.forName(driver);
			//connect to database
            conn = DriverManager.getConnection(url, user, password); 
            if(!conn.isClosed())
                System.out.println("Succeeded connecting to the Database!"); 
        } catch (SQLException e) {
            System.out.println("MySQL Error");
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } 
    }
	
	public void Connect(String url, String user, String password){
	//build a connection to database according to parameters
        String driver = "com.mysql.jdbc.Driver";       
        try {
            Class.forName(driver);
            conn = DriverManager.getConnection(url, user, password); 
            if(!conn.isClosed())
                System.out.println("Succeeded connecting to the Database!"); 
        } catch (SQLException e) {
            System.out.println("MySQL Error");
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } 
}	
	
	public ResultSet SelectData(String sql){
	//Select data from database, and return the result set 
		ResultSet result = null;
		try {
            Statement stmt = conn.createStatement();
            //sql = "select * from students;";
            System.out.println("SQL: "+sql);
            result = stmt.executeQuery(sql);
        } catch (SQLException e) {
            System.out.println("MySQL Select Error");
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
		return result;
	}
	
	public int UpdateData(String sql){
	//update database including create, delete, update, return rows affected 
		int result = -1;
		try {
            Statement stmt = conn.createStatement();
            //sql = "select * from students;";
            System.out.println("SQL: "+sql);
            result = stmt.executeUpdate(sql);
        } catch (SQLException e) {
            System.out.println("MySQL Update Error");
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
		return result;
	}
	
	public void Close() throws SQLException{
		//Close the connection to database
		conn.close();
	}
	
	public static void main(String[] args) throws Exception {
		//Create MySQL object that connects to the database
		mp1 test = new mp1();
		int theResult = 0;
		
		//Select all from question table and print it to console
		ResultSet question = test.SelectData("SELECT * FROM question");
		while (question.next()) {
			System.out.println(question.getString(1) + "\t" 
            			+ question.getInt(2)+"\t"
            			+ question.getInt(3));
		}
		System.out.println();
		
		//Select all from question table with only my name and perform a calculation
		ResultSet question1 = test.SelectData("SELECT * FROM question WHERE name = 'Melcher, Jack Collin Koakaikaina'");
		while (question1.next()) {
			System.out.println(question1.getString(1) + "\t" 
						+ question1.getInt(2)+"\t"
            			+ question1.getInt(3));
			//A * B + last 2 digits of my student id
			theResult = question1.getInt(2) * question1.getInt(3) + 25;
			System.out.println(question1.getInt(2) + " * " + question1.getInt(3) + " + 25 = " + theResult);
		}
		System.out.println();

		//Insert my name, id2d, and result into the result table
		String sql = "INSERT IGNORE INTO result (name, id2d, result) "
					+ "VALUES ('Melcher, Jack Collin Koakaikaina', 25, " + theResult +")";
		test.UpdateData(sql);
		System.out.println();

		//Select name and result from result table thats associated to myself and print it to console
		ResultSet result = test.SelectData("SELECT name, result FROM result WHERE name = 'Melcher, Jack Collin Koakaikaina'");
		while (result.next()) {
			System.out.println(result.getString(1) + "\t" 
            			+ result.getInt(2));
		}
		System.out.println();
		
		
		test.Close();
	}
}

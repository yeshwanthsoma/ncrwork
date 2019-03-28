using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;


namespace Class
{
    public class Class1
    {
        public string init(string user,string Upass)
        {
            string role="00", pwd="oo", isEna="00";
            int flag = 0;
            SqlConnection con = new SqlConnection(@"Data Source=DESKTOP-R5QLBIQ\SQLEXPRESS;Initial Catalog=Project;Integrated Security=True");
            con.Open();
            string sql = "checkcre";
            SqlCommand command = new SqlCommand(sql, con);
            SqlParameter param1 = new SqlParameter("@uid", user);
            command.Parameters.Add(param1);

            command.CommandType = CommandType.StoredProcedure;
            SqlDataReader dr = command.ExecuteReader();
            if(dr.Read())
            {
                 role = dr.GetString(0);
                 pwd = dr.GetString(1);
                 isEna = dr.GetString(2);
            }
            con.Close();
            if (Upass.Equals(pwd)) 
            {
                if(isEna=="yes"&& role == "user")
                {
                    flag = 1;
                }
                else if(isEna == "yes" && role == "HR")
                {
                    flag = 2;
                }
      

            }

            if (flag == 1)
            {
                return "USER";
            }
            else if (flag == 2)
            {
                return "HR";
            }
            else
            {
                return "WRONG";
            }

        }
        public SqlDataReader print()
        {
            SqlConnection con = new SqlConnection(@"Data Source=DESKTOP-R5QLBIQ\SQLEXPRESS;Initial Catalog=Project;Integrated Security=True");
            con.Open();
            string sql = "prints";
            SqlCommand command = new SqlCommand(sql, con);



            command.CommandType = CommandType.StoredProcedure;
            SqlDataReader dr = command.ExecuteReader();
            
            return dr;
            
           
        }


    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;


public partial class HR : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        Class.Class1 obj = new Class.Class1();
        SqlDataReader dr=obj.print();
        GridView1.DataSource = dr;
        GridView1.DataBind();



    }

    
}
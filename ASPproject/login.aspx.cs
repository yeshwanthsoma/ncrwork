using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
     
        Class.Class1 obj = new Class.Class1();
        string res=obj.init(Username.Text, Password.Text);
        if (res == "HR")
        {
            Session["Role"] = "HR";
            Session["Id"] = Username.Text;
            Response.Redirect("HR.aspx");
        }
       else  if(res=="USER")
        {
            Session["Role"] = "USER";
            Session["Id"] = Username.Text;

        }
    }
}
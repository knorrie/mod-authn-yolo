Yolo style authentication for Apache 2
======================================

The `authn_yolo` module is an authentication provider for Basic Authentication
in the Apache2 web server. It accepts any combination of user and password.

Sometimes this is useful when testing or building a proof of concept, since
there's no need to generate a htpasswd file etc. It can also be used to pass a
user name to Apache in a scenario where verification of the credentials is
delegated to a reverse proxy in front of Apache.

```
<Location />
    AuthType Basic
    AuthName "Yolo"
    AuthBasicProvider yolo
    Require valid-user
</Location>
```

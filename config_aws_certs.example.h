// The MQTTT endpoint for the device (unique for each AWS account but shared amongst devices within the account)
#define AWS_IOT_ENDPOINT "a1b2c3d4e5f6g7-ats.iot.us-east-1.amazonaws.com"

// Paste your AWS IoT certificate that's assinged to your thing here
const char AWS_CERT_CRT[] = R"(-----BEGIN CERTIFICATE-----
MIIDBzCCAe+gAwIBAgIJAMidLKcw6SK3MA0GCSqGSIb3DQEBBQUAMBoxGDAWBgNV
BAMMD3d3dy5leGFtcGxlLmNvbTAeFw0xOTExMDIwNDE5MzBaFw0yOTEwMzAwNDE5
MzBaMBoxGDAWBgNVBAMMD3d3dy5leGFtcGxlLmNvbTCCASIwDQYJKoZIhvcNAQEB
BQADggEPADCCAQoCggEBAMXZWOaT0JdGmNX2RroRCjZhk+7ajF8GoxbaHMfa7h/s
xI11hl4epKkxesTk3DXaYSnsA8cMce0XBpCGXXRcSwzeWe1V6g4wMv/Tp13hW549
5Ci8Wt0drFpCyfVFpoMhuHqwY7qaMAAlexwd3CcEj6kJ+gxEBJ3zd8JOnM9WgyN0
76Mzp8zdGANze0w9/JEE8JzD/Y8dO59b0IggfePXiyk+qwv6YMJIjaS11P/Wkbve
GqPBvP639CdOJhUJ97HjwuNZV9R5Z7zJ0EL2QRuu5hx4cvprPa5tFXshqFOcS+FD
cxdt0yvte8HJcJDQaK+/YVQilaxp1lB13jUESK7rCYUCAwEAAaNQME4wHQYDVR0O
BBYEFF9/5nmJitAhhiDMT2r7ywfguYl2MB8GA1UdIwQYMBaAFF9/5nmJitAhhiDM
T2r7ywfguYl2MAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQEFBQADggEBAGjGV48u
TvMA0nIf9mrNo5M61UyJPqRLtSKCRlIqiqBb3oFl7JVmIimMJXlMwukOHBfu2gLq
ywYaRCvyYVGVt/C6q3E3LZL4iiYMoy/YoQ8VtxSC0Kt6eticKaEsmT8zbNu6tWUN
1JKTpP5PKhb1pU4xIX44BOgUj4EYeT6r4MTXKR6LdiGOaVb2BmGC+h7LihDDtFhq
DlX+OF7mUQgWRWzAnF6eDDnxzSMjDfVqiVTu+mxlZjRvDE+fDV2SiGcsqdh52IHA
b2THewEonVfXrv1v66W0GYsSUbtw5Dm4yHmTYehtsob1rdAB044lmtq3kjyxpEMz
QDY5iBaSC98dTEE=
-----END CERTIFICATE-----)";

// Paste your AWS IoT key that's assinged to your thing here
const char AWS_CERT_PRIVATE[] = R"(-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAxdlY5pPQl0aY1fZGuhEKNmGT7tqMXwajFtocx9ruH+zEjXWG
Xh6kqTF6xOTcNdphKewDxwxx7RcGkIZddFxLDN5Z7VXqDjAy/9OnXeFbnj3kKLxa
3R2sWkLJ9UWmgyG4erBjupowACV7HB3cJwSPqQn6DEQEnfN3wk6cz1aDI3TvozOn
zN0YA3N7TD38kQTwnMP9jx07n1vQiCB949eLKT6rC/pgwkiNpLXU/9aRu94ao8G8
/rf0J04mFQn3sePC41lX1HlnvMnQQvZBG67mHHhy+ms9rm0VeyGoU5xL4UNzF23T
K+17wclwkNBor79hVCKVrGnWUHXeNQRIrusJhQIDAQABAoIBACCtLQmoECNr/YIZ
EsVYWx9wLkacweJP7k+v5mD7v6h2KmBSsMaKuRdYnLY4NkaOss2BtX4CiC5oRyVH
i9fUBnExqBiSv/1n6IRoKJRQzBjuj+hKc5dhdz3RGhnwTvgJcbaRu2buYE8l4Zdb
Nykaj7+TbkDoWvrbY0QsR6nW2AHa27so5XFylfyV/U672cVWEuSozYbUV78gLpU4
qVDRmOi7Hz4mxy7s5wwRW2YWlECRt6FIpnFXxE53AyWejLm7Yx844aSDvGuchsKh
lgTkNFDl4PiUDTkOP4pxmS9TKJ+DxY+vCgQzAfgEWrYWfJhvMvryZeOK+TWaOOeP
6JDWvgECgYEA9VrJsVDVPNGU6Y3py4xnyCiVknhyCYLvt2otgn1yngSl0+/Yyvo8
3U4MVmUi9Hv51VBdXQDp/p0a8u7bkGEN9vrGpBniqms1f+2AutSVflo+jqtEmntv
j+XqsS483T0zgp+7cMxtnoNLfO+FMEoPsLj24b/q4mm72FvIbhDw0BUCgYEAzm7n
NH1avkPwf9iZ/2rKX6NlbS21Qews9Nmpmn1oq26r83YNZxngaGqE/WM3cAx5jVft
Lf45rLxzfifYEZjr0bZWg1pX5mR6VgevmKrCh51HSA8UVhH8X1ikDaPZ2gxm2wFV
EF5vQdTz9CPR368Ce5OqEyUMjtmXDfE+f/feP7ECgYEAv8zZHuQxzfmIj4uA2L5J
4w7W3kmJ3CWff6JhMUEf+KdpeuRkdUhpjBcXTfKCAN1p0HeihLHSOlhWWNKgkZ1N
bWVdI6uYpeBpUjg4CdVliADEJoN8fcdAzxzM+vVKXykYu2RjAyrMBr5cpK4ZUEaV
PXFajd+ZnqVJUzls1Z4oooECgYB3LBsZeEyMjpgmlhrBExtlfuSs1LhRKFEDwSxi
XYexgCCQWlR+crfUT7oatc5pRypc6Kep55vQFrLt336jGg75cDQdfGhGPzdItwMu
NVY8CBYAiYQJ9DQnrvp2TWMUuBgg0nITExFTheaXyJ3+bgAW6zZB+x920DKd/+k+
4w9Q4QKBgB3kyvLt4IARyvvtI9pvum5klPiLyDa4fmPnp5OkGgP/rJGR1LbFhqYC
OIAn8i/FCGMuYiRJx0zDBOcMRQQ6Gnb3+zgeahTjbtU5GAElG8bjBWU8aTA1DjcF
y1XY7vFhptUmg0USUCwLt8PmXXDhbXCVuWlkj+6Yu+z6PCQuKwWs
-----END RSA PRIVATE KEY-----)";

// Most of the time, this will not change.
//
//   AWS ATS Root CA Cert
//     CN=Amazon Root CA 1,O=Amazon,C=US
//
const char AWS_CERT_CA[] = R"(-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----)";

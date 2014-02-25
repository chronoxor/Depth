


var gBVType='firefox',gBVVersion='20',gOSType='windows nt 5';

/* This source code is Copyright (c) Vibrant Media 2001-2007 and forms part of the
patent-pending Vibrant Media product "IntelliTXT" (sm). */
function lES(url){
var e = document.createElement("script");
e.src = url;
e.type="text/javascript";
document.getElementsByTagName("body")[0].appendChild(e);
}

function iG(){
gHN=new Array();
gAN=new Array();
gSN=new Array('<b>','<h1>','<h2>','<h3>','<h4>','<h5>','<strong>','<em>','<i>','cpp-keyword','cpp-literal','cpp-comment','!ForumTable','smalltext');
}

function kwM(){
var ad=fABDID(aAD,gDI);
if(null==ad)return;
window.status=ad.t.replace(/\&pound\;/, '?');
}

var gWriteStyleBlock=1,
gCLM=1,
gK=new Array(),
gKL=new Array();

gITXTNIdx=0;
function cpl(s){
var p=s.indexOf(' '),
c=1;
while(p>=0){
p=s.indexOf(' ',p+1);
c++;
}
return c;
}
for (var i=0;i<gK.length;i++)
gKL[i]=cpl(gK[i]);

function doIt(){

ipartid=1369;
ibid=2745;
ipid=5102;
ts='20070218145846';
mk=3;
server='codeproject.us.intellitxt.com';
cc='us';
rcc='a2';
itxtreg='--';
itxtdma='0';
ulS='font-weight:normal;font-size:100%;text-decoration:underline;border-bottom:darkgreen 0.075em solid;padding-bottom: 1px;color:darkgreen;background-color:transparent;padding-bottom:1px';
hS='font-weight:normal;font-size:100%;text-decoration:underline;border-bottom:darkgreen 0.2em solid;padding-bottom: 1px;color:darkgreen;background-color:transparent;padding-bottom:1px';
iEulS='';
iEhS='';
bWTL=true;
sWTU='http://secure.codeproject.com/info/intelliTXT.asp';
bTtl=false;
iCF=3;
gDBL=0;
kwpn=1;
gTI='';
gATIg='';
gATIr='http://images.intellitxt.com/ast/adTypes/';
gATIs='height:10px;width:10px;position:relative;top:4px;left:1px;padding:0px;padding-right:0px;margin:0px;';
gFTTm='';
gFTTr='http://demos.us.intellitxt.com/demos/lab/flashAdUnit/v1.1/swf/';
gSI=1;
gSID='3a5493e28c4859dc2ebee087dee64436';
mTL=50;
gDrag=1;
gOFlt=0;
gIRB=0;
gTTt=1500;
gDASB=3;
gAUAT=0;
gDAT='6,11,12,17,18,22,25';
gEAT='';
iTTC=0;

gLCL=0;
if('v1'==gCM)mTL=0;
ndbST=new Date().getTime();
iDW();
if(gCM=='v1')
gITXTN=gIA2();
else
gITXTN=gIA(gdB, gCM, 0);
var bCF=1;

var tTXT='',aIEE;

if(tTXT.length==0)tTXT=document.title;
var aCs=new Array();
if (gITXTN!=null && gITXTN.length)
for(var i=0;i<gITXTN.length;i++){
var re2=/\\/g,
re3=/[\(\)]|<br>/g,
re4=/(\w+):\/\/([^\/:]+)(:\d*)?([^# ]*)/g,
re5=/<a[\s]+[^>]*?href[\s]?=[\s\"\']+(.*?)[\"\']+.*?>([^<]+|.*?)?<\/a>/g,
re7=/(\s{2,})/g,
re8=/(\s{2,})/g,
re9=/\n/g;
var re6=/[^-|^a-z|^A-Z|^0-9|^\x7f-\xff|^\/|^#|^+]/g,
sContents=tmA(gT(gITXTN[i]).replace(re2,'/').replace(re7,' ').replace(re3,' ').replace(re4,' ').replace(re5,' ').replace(re6,' ').replace(re8,'  '));

if(sContents.length>0){
aCs[aCs.length]=sContents+' zxz ';
gCL+=aCs[aCs.length-1].length;
}
}

if(aCs.length>0)gCL+=5;

if( true && ((bCF==1 && gCL) || (gIRB==1 && bCF==0 && gCL>=(gLCL * 1.1)) || (gDTo==false && gIRB==1 && bCF==0 && Math.abs(gCL-gLCL)>=(gLCL * 10) / 100))) {
gINt=' zxz ';
for(var i=0;i<aCs.length;i++)
gINt+=aCs[i];
var pTx=gINt,
nC=0,cn=0,sTx='',sSptTs=(new Date()).getTime(),chnkSz=(iNBc?250:500);
if (escape(pTx).length>chnkSz) {
   
sTx=pTx.substring(0,chnkSz);
while (sTx.length==chnkSz) {
    
lES('http://'+server+'/v3/chunks.jsp?ipid='+ipid+'&sid='+gSID+'&ts='+sSptTs+'&enc='+gENC+'&cn='+cn+'&tx='+escape(sTx));

nC+=chnkSz;cn++;
sTx=pTx.substring(nC, nC+chnkSz);
}
   
lES('http://'+server+'/v3/chunks.jsp?ipid='+ipid+'&sid='+gSID+'&nbc='+iNBc+'&ts='+sSptTs+'&enc='+gENC+'&cn='+cn+'&tx='+escape(sTx));
var sSpt = 'http://'+server+'/v3/spit.jsp?ipid='+ipid+'&ts='+sSptTs+'&pagecl=24392&cc='+cc+'&rcc='+rcc+'&reg='+itxtreg+'&dma='+itxtdma+'&dfr=false&cn='+cn+'&cf='+iCF+'&mk='+mk+'&kwpn='+kwpn+'&sid='+gSID+'&si='+gSI+'&rdtm='+iRDTM+'&rrm='+iRRM+'&rcpcm='+iRCPCM+'&ripsm='+iRIPSM+'&rorm='+iRORM+'&wpsm='+iWPSM+'&wpim='+iWPIM+'&dfc='+iDFC+'&rp='+bYCR+'&so='+iSo+'&nbc='+iNBc+'&adi='+iADi+'&ac=0&dat='+gDAT+'&eat='+gEAT+'&irb='+gIRB+'&enc='+gENC+'&ims=2&iek=0&iel=5&ieak=0&iedm=0&iebc=cyan&ttxt='+escape(tTXT)+'&auat=0&lpgv=0&ru='+escape(sRU);

window.setTimeout('lES(\''+sSpt+'\');', 250);
} else

lES('http://'+server+'/v3/spit.jsp?ipid='+ipid+'&ts='+sSptTs+'&pagecl=24392&cc='+cc+'&rcc='+rcc+'&reg='+itxtreg+'&dma='+itxtdma+'&dfr=false&cf='+iCF+'&mk='+mk+'&kwpn='+kwpn+'&sid='+gSID+'&si='+gSI+'&rdtm='+iRDTM+'&rrm='+iRRM+'&rcpcm='+iRCPCM+'&ripsm='+iRIPSM+'&rorm='+iRORM+'&wpsm='+iWPSM+'&wpim='+iWPIM+'&dfc='+iDFC+'&rp='+bYCR+'&so='+iSo+'&nbc='+iNBc+'&adi='+iADi+'&ac=0&dat='+gDAT+'&eat='+gEAT+'&irb='+gIRB+'&enc='+gENC+'&ims=2&iek=0&iel=5&ieak=0&iedm=0&iebc=cyan&ttxt='+escape(tTXT)+'&auat=0&lpgv=0&ru='+escape(sRU)+'&tx='+escape(pTx));

gSpitTimer = window.setInterval('checkSpit();', 5000);
} else if (gCL)

 {

if ((gITXTN == null) || (gITXTN != null && gITXTN.length==0))
gITXTN=gIA(gdB, gCM, 0);
if (gITXTN != null && gITXTN.length)
if (gCL>0) rKWL(250);

}
}
var ndbST,
iRDTM=100000000,
iRRM=100000,
iRCPCM=10000,
iRIPSM=1000,
iRORM=10000,
iWPSM=75,
iWPIM=50,
iDFC=0,
iTTl=1,
iTTp=0,
iSo=0,
iNBc=0,
iADi=0,
sKPs='~',
sKFs='|',
sRU='http://www.codeproject.com/library/libreflection.asp',
gMR=1000,
bWAC=0,
bYCR=0,
gMNC=255,
gTTD=500,
iIEK=0,
sIEFH='',
iDAH=0,
sTTBG='#EEEEEE',
sTTHV='#FFFFE0',
sTTTc='#0000DE',
sTTHTc='#0000DE',
sTTDc='#000000',
sTTAc='#008000',
sTTHAc='#008000',
gFES=0,
gSDCv=0,
gPmoe=0;
var sspl='Advertisement',
swti='What\'s this?',
slm='LEARN MORE',
ssch='Searching...',
sbn='Buy now',
scls='Close',
sCC='$',
sEet='End time',
sEcb='Place bid',
sEsn='Seller',
ierl='Related Links',
iept='Page Title',
iert='Relevancy';
var gNeedProtos=1;

var prevOnload=(window.onload?window.onload:new Function()),
itxtInited=0,
itxtPrevOnloadCalled=0;
function itxtOnloader() {
 
startIntelliTXT(0);
}
function itxtStateChange() {
 
startIntelliTXT(1);
}
function startIntelliTXT(v) {
 
if (!v) {
if( itxtPrevOnloadCalled )
return;
itxtPrevOnloadCalled=1;
prevOnload();
}
if (itxtInited) return;
 
itxtInited=1;
lES('http://codeproject.us.intellitxt.com/v3/func_033.js?v=200702081226');
}
window.onload=itxtOnloader;
window.setTimeout('startIntelliTXT(1);',3000);


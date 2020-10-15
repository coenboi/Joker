#ifndef BAPI_H
#define BAPI_H
#include <string>

// Shared Variables
const short BAPI_ADM = 1;
const short BAPI_SUP = 2;
const short BAPI_MOD = 3;
const short BAPI_STU = 4;
const short BAPI_EMP = 5;

/*	RETURN CONVENTIONS
*
*	bool chk::user(): TRUE or FALSE;
*	string chk::authLogin(): "xxxxxxxxxx";
*	bool chk::logout(): TRUE or FALSE;
*
*	string get::attr::users():	"#BLK_ADM, count, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
*								"#BLK_STU, count, 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
*								"#BLK_EMP, count, 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
*								"#BLK_SUP, count, 0:(BIDxxxxxxxxxx,Name,SUP), 1:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
*								"#BLK_MOD, count, 0:(BIDxxxxxxxxxx,Name,MOD), 1:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
*								"#BLK_GUE, count, 0:(BGIDxxxxxxxxxx,Name,Duration), 1:(BGIDxxxxxxxxxx,Name,Duration), ... n:(BGIDxxxxxxxxxx,Name,Duration)"
*	string get::attr::user():	"#USR_ATTR_ADM, BID:'BIDxxxxxxxxxx', AID : 'xxxxxxxxxx', NET : 'NETxxxxxxxxxx', OWN : '0 or 1', NAME : 'xxxxxxxxxx', GUARDIAN : 'xxxxxxxxxx', DOB : '00/MON/0000', ACT_STAT : '0 or 1', PH1 : 'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2 : 'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1 : 'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2 : 'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1 : 'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2 == ADD1 : '0', ADD2 : 'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE : '0 or 1', ACC_STAT : 'xxxxxxxxxx'"
*								"#USR_ATTR_STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*								"#USR_ATTR_EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*				//INCOMPLETE	"#USR_ATTR_SUP, BID:'BIDxxxxxxxxxx', SUP:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*				//INCOMPLETE	"#USR_ATTR_MOD, BID:'BIDxxxxxxxxxx', MOD:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*				//INCOMPLETE	"#USR_ATTR_GUE, GID:'BGIDxxxxxxxxxx', Name:'xxxxxxxxxx', START:'00:00,00/00/00', END:'00:00,00/MON/0000', DUR:'00:00:00', IP:'000:000:000'"
*
*	bool up::attr::users():		TRUE or FALSE;
*	bool up::attr::user():		TRUE or FALSE;
*
*	bool post::attr::users():	TRUE or FALSE;
*	bool post::attr::user():	TRUE or FALSE;
*
*	bool pop::attr::user():	TRUE or FALSE;
*/

namespace bapi {

	// USER APIs

	namespace user { // User Functions
		namespace chk { // Check Functions
			bool user(std::string access_code, short which, std::string username, std::string NET);
			std::string authLogin(std::string access_code, short key, std::string username, std::string NET, std::string password);
			bool logout(std::string access_code, std::string session_code, std::string BID, std::string data);
		}
		namespace get { // Get Functions
			namespace attr { // Attribute Functions
				std::string users(std::string access_code, std::string session_code, std::string net, short usertype);
				std::string user(std::string access_code, std::string session_code, std::string NET, std::string BID_requestedBy, std::string BID_requested);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace up { //Update Functions
			namespace attr { //Attribute Functions
				bool users(std::string access_code, std::string session_code, std::string bid, short action);	//Consider removal.
				bool user(std::string access_code, std::string session_code, std::string bid, std::string data);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace post { //Post Functions
			namespace attr { //Attribute Functions
				bool users(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data);	//Consider removal
				bool user(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace pop { // Post Functions
			namespace attr { // Attribute Functions
				bool user(std::string access_code, std::string session_code, std::string BID_requestBy, std::string BID_requestOn, short action);
			}
			//namespace msg {}
			//namespace notif {}
		}
	}

	// NETWORK APIs

	/*	RETURN CONVENTIONS
*
*	bool chk::user(): TRUE or FALSE;
*	bool chk::net(): TRUE or FALSE;
*	bool chk::owner(): TRUE or FALSE;
*	bool chk::active(): TRUE or FALSE;
*
*	string get::net(): "#NET, NET:'NETxxxxxxxxxx', ORG:'xxxxxxxxxx', OWN:'BIDxxxxxxxxxx', ADM:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', SUP:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', MOD:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', USER:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', STD:'count,(STDxxxxxxxxxx, STDxxxxxxxxxx, ...)', CYC:'count,(CYCxxxxxxxxxx, CYCxxxxxxxxxx, ...)', LCK:'count,(LCKxxxxxxxxxx,LCKxxxxxxxxxx,...)', CAP:'count', TXN:'TXNxxxxxxxxxx'";
*	string get::stats(): "#NET_STAT, INCOMPLETE";
*	string get::admins(): "#NET_ADMS, count:'xxxx', 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
*	string get::owner(): "#NET_OWN, BID:'BIDxxxxxxxxxx'";
*
*	string get::stands(): "#NET_STDS, count:'xxxx', 0:'STDxxxxxxxxxx', 1:'STDxxxxxxxxxx', ... n:'STDxxxxxxxxxx'";
*	string get::stand(): "#NET_STD, TIME:'00:00:00, DD/MMM/YYYY', STD:'STDxxxxxxxxxx', ACT_STAT:'0 or 1', STD_STAT:'xxxxxxxxxx', NAME:'xxxxxxxxxx', LOC:'xxxxxxxxxx', GPS:(xxxxxx,xxxxxx), CAP:'xxx', TXN_COUNT:'xxxxxxxxxx'";
*	string get::standStats(): "#NET_STD_STAT, INCOMPLETE";
*	string get::nearestStand(): "#NET_NEAR_STD, 0:(DIST,STDxxxxxxxxxx), 1:(DIST,STDxxxxxxxxx), 2:(DIST,STDxxxxxxxxxx)";
*	int get::standDistance(): int distance;
*
*	string get::cycles(): "#NET_CYCS, count:'xxxx', 0:'CYCxxxxxxxxxx', 1:'CYCxxxxxxxxxx', ... n:'CYCxxxxxxxxxx'";
*	string get::cycle(): "#NET_CYC, TIME:'00:00:00,DD/MMM/YYYY', CYC:'CYCxxxxxxxxxx', CYC_STAT:'xxxxxxxxxx', ISSUED:'0 or 1', LOC:'STDxxxxxxxxxx or BIDxxxxxxxxxx', WITH:'BIDxxxxxxxxxx', HEALTH:'xxxxxx'";
*	string get::freeCycles(): "#NET_FREE_CYC, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(STDxxxxxxxxxx,CYCxxxxxxxxxx), 1:(STDxxxxxxxxxx,CYCxxxxxxxxxx), ... n:(STDxxxxxxxxxx,CYCxxxxxxxxxx),"
*
*	string get::locks(): "#NET_LCKS, count:'xxxx', 0:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx), 1:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx), ... n:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx)"
*	string get::lock(): "#NET_LCK, TIME:'00:00:00,DD/MMM/YYYY', STD:'STDxxxxxxxxxx', OPEN:'0 or 1', ENABLED:'0 or 1'";
*
*	string get::allTXN(): "#NET_TXNS, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')";
*	string get::userTXN(): "#NET_USR_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,txnStatus,issuedAt,overtime), 1:(TXNxxxxxxxxxx,txnStatus,issuedAt,overtime), ... n:(TXNxxxxxxxxxx,txnStatus,issuedAt,overtime)";
*	string get::stdTXN(): "#NET_STD_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')";
*	string get::cycTXN(): "#NET_CYC_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issuedAt,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issuedAt,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issuedAt,'00:00:00,DD/MMM/YYYY')"";
*	string get::TXN(): "#NET_TXN, TXN:'TXNxxxxxxxxxx', ISSUED_AT:'00:00:00,DD/MMM/YYYY', DEPOSIT_AT:'time or NULL', FROM:'STDxxxxxxxxxx', AT:'STDxxxxxxxxxx or NULL', OVERTIME:'00:00:00', COMPLETE:'0 or 1', TXN_STAT:'xxxxxx', NOTE:'xxxxxxxxxxxxxxxxxx'";
*
*	bool up::net(): TRUE or FALSE;
*
*	bool up::stands(): TRUE or FALSE;
*	bool up::stand(): TRUE or FALSE;
*
*	bool up::cycles(): TRUE or FALSE;
*	bool up::cycle(): TRUE or FALSE;
*
*	bool up::locks(): TRUE or FALSE;
*	bool up::lock(): TRUE or FALSE;
*
*	bool post::net(): TRUE or FALSE;
*
*	bool post::stand(): TRUE or FALSE;
*
*	bool post::cycle(): TRUE or FALSE;
*
*	bool post::lock(): TRUE or FALSE;
*
*	bool pop::net(): TRUE or FALSE;
*
*	bool pop::stand(): TRUE or FALSE;
*
*	bool pop::cycle(): TRUE or FALSE;
*
*	bool pop::lock(): TRUE or FALSE;
*/

	namespace net { // Network Functions
		namespace chk { // Check Functions
			bool net(std::string access_code, std::string NET);
			bool user(std::string access_code, short key, std::string NET, std::string BID);
			bool owner(std::string access_code, std::string NET, std::string BID);
			bool active(std::string access_code, std::string NET);
		}
		namespace get { // Get Functions
			std::string net(std::string access_code, std::string session_code, std::string NET, std::string BID);
			std::string stats(std::string access_code, std::string session_code, std::string NET, std::string BID);
			std::string admins(std::string access_code, std::string session_code, std::string NET, std::string BID);
			std::string owner(std::string access_code, std::string session_code, std::string NET, std::string BID);

			std::string stands(std::string access_code, std::string session_code, std::string NET, std::string BID);
			std::string stand(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID);
			std::string standStats(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID);
			std::string nearestStand(std::string access_code, std::string session_code, std::string NET, std::string LOC, std::string BID);
			int standDistance(std::string access_code, std::string session_code, std::string NET, std::string STD1, std::string STD2, std::string BID);

			std::string cycles(std::string access_code, std::string session_code, std::string NET, std::string BID);
			std::string cycle(std::string access_code, std::string session_code, std::string NET, std::string CYC);
			std::string freeCycles(std::string access_code, std::string session_code, std::string NET, std::string BID);

			std::string locks(std::string access_code, std::string session_code, std::string NET, std::string BID);
			std::string lock(std::string access_code, std::string session_code, std::string NET, std::string LCK, std::string BID);

			std::string allTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester);
			std::string userTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string BID_requested);
			std::string stdTXN(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID_requester);
			std::string cycTXN(std::string access_code, std::string session_code, std::string NET, std::string CYC, std::string BID_requester);
			std::string TXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string TXN);
		}
		namespace up { // Update Functions
			bool net(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data);

			bool stands(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data);
			bool stand(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string STD, std::string data);

			bool cycles(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data);
			bool cycle(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string CYC, std::string data);

			bool locks(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data);
			bool lock(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string LCK, std::string data);
		}
		namespace post { // Post Functions
			bool net(std::string access_code, std::string session_code, std::string BID, std::string data);

			bool stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data);

			bool cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data);

			bool lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string data);
		}
		namespace pop { // Pop Functions
			bool net(std::string access_code, std::string session_code, std::string BID, std::string NET);

			bool stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD);

			bool cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string CYC);

			bool lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string LCK);
		}
	}
}

#endif // BAPI_H

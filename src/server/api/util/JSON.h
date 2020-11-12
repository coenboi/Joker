// Testing Incomplete

// JSON template wrapper definition

//JSON works as a redundant (underlined) management tool.
//It just parses the strings received from bapi.h into useful chunks of trivial data types.
//The JSON object can then be passed to initialize the higher objects such as Admin and Users.
//JSON removes the requirement of translating recevived strings by the higher objects so that they can focus on other important stuff.
//It also helps in separting a specific part of the code so that it can be debugged later on.

/*
Example Usage:
...
JSON j_Network(getNetwork(par1, par2, ...),key);
Network network(j_Network);

in implementation it should simplify initialization as

Network::network(JSON j_Network){
	attribute1 = j_Network.getAttr1();
	attribute2 = j_Network.getAttr2();
	attribute3 = j_Network.getAttr3();
	...
}
*/

// Sample User Data

// "BID:'BID016', TYPE:'STU', IS_ACTIVE:'F', ONLINE:'F', ACCOUNT_STAT:'1',
// PROFILE_COMPLETE:'F', LOG_COUNT:'685', NET:'NET100', OWN:'F', SID:'2017-310-132',
// NET:'NET100', PEN:'0', NAME:'Owen Goldston', GUARDIAN:'Saleem Longford',
// DOB:'14/JAN/1994', GENDER:'M', PH1:'CODE:(972), NUM:(9477757029)', PH2:'CODE:(86),
// NUM:(2114977381)', EM1:'HEAD:(slongfordc), HOST:(digg.com)', EM2:'HEAD:(slongfordc),
// HOST:(woothemes.com)', ADD1:'HNO:(51775), BLO:(S), COL:(Buena Vista Park), LAN:NULL,
// AREA:NULL, CIT:NULL, STA:NULL, COU:NULL, PIN:NULL', ADD2==ADD1:'F', ADD2:'HNO:(245), BLO:(H),
// COL:NULL, LAN:NULL, AREA:(Lillian Hill), CIT:NULL, STA:NULL, COU:NULL, PIN:NULL', DEPT:'Sales'"

#pragma once
#include <string>
#include <map>	// CURRENTLY USING MAPS FOR ACCELERATING THE DEVELOPMENT. LATER WILL USE INBUILT PAIRS.
#include <list>

//template <class T, class Y>;
class JSON {
private:
	// Private Variables
	enum class prefix_type {
		_PTYPE_empty,
		_PTYPE_ALL_ADM,
		_PTYPE_ALL_SUP,
		_PTYPE_ALL_MOD,
		_PTYPE_ALL_STU,
		_PTYPE_ALL_EMP,
		_PTYPE_ALL_GUE,
		_PTYPE_ALL_NET,
		_PTYPE_ALL_STD,
		_PTYPE_ALL_CYC,
		_PTYPE_ALL_LCK,
		_PTYPE_ALL_TXN,

		_PTYPE_ATR_ADM,
		_PTYPE_ATR_SUP,
		_PTYPE_ATR_MOD,
		_PTYPE_ATR_STU,
		_PTYPE_ATR_EMP,
		_PTYPE_ATR_GUE,

		_PTYPE_NET_STAT,
		_PTYPE_NET_ADMS,
		_PTYPE_NET_OWN,

		_PTYPE_NET_STD,
		_PTYPE_NET_STD_STAT,
		_PTYPE_NET_NEAR_STD,
		_PTYPE_NET_STD_VACANT,

		_PTYPE_NET_CYC,
		_PTYPE_NET_CYC_FREE,
		
		_PTYPE_NET_LCK,
		_PTYPE_NET_LCK_STAT,

		_PTYPE_TXN,
		_PTYPE_NET_USR_TXN,
		_PTYPE_NET_STD_TXN,
		_PTYPE_NET_CYC_TXN,
	};
	struct data_types {
		const std::string ALL_DATA = "ALL_DATA";
		const std::string USR_DATA = "USR_DATA";
		const std::string NET_DATA = "NET_DATA";
		const std::string STD_DATA = "STD_DATA";
		const std::string CYC_DATA = "CYC_DATA";
		const std::string LCK_DATA = "LCK_DATA";
		const std::string TXN_DATA = "TXN_DATA";
	};
	prefix_type m_prefix = prefix_type::_PTYPE_empty;
	std::string m_type = "empty";
	//std::map<T, Y> m_default_tag_list;
	//std::map<T, Y> m_custom_tag_list;
	std::map<std::string, std::string> m_default_container;
	std::map<std::string, std::string> m_custom_tag_list;
	// size_t m_default_tags = m_default_tag_list.size();
	// size_t m_custom_tags = m_custom_tag_list.size();

	/*
	struct Pair {
		std::string TAG;
		std::string DATA;
	};

	struct Tag {
		std::string TAG_NAME;
		Pair _data;
		Tag* previous_tag = nullptr;
		Tag* next_Tag = nullptr;
	};
	*/
private:
	// Private Methods
	JSON();
	void add_ALL_ADM(std::string input_data);
	void add_ALL_SUP(std::string input_data);
	void add_ALL_MOD(std::string input_data);
	void add_ALL_STU(std::string input_data);
	void add_ALL_EMP(std::string input_data);
	void add_ALL_GUE(std::string input_data);
	void add_ALL_NET(std::string input_data);
	void add_ALL_STD(std::string input_data);
	void add_ALL_CYC(std::string input_data);
	void add_ALL_LCK(std::string input_data);
	void add_ALL_TXN(std::string input_data);

	void add_ATR_ADM();
	void add_ATR_SUP();
	void add_ATR_MOD();
	void add_ATR_STU();
	void add_ATR_EMP();
	void add_ATR_GUE();

	void add_NET_STAT();
	void add_NET_ADMS();
	void add_NET_OWN();

	void add_NET_STD();
	void add_NET_STD_STAT();
	void add_NET_NEAR_STD();
	void add_NET_STD_VACANT();

	void add_NET_CYC();
	void add_NET_CYC_FREE();

	void add_NET_LCK();
	void add_NET_LCK_STAT();

	void add_TXN();
	void add_NET_USR_TXN();
	void add_NET_STD_TXN();
	void add_NET_CYC_TXN();

	void m_add_tag(std::string tag_to_add, std::string data_for_tag);
	void m_remove_tag(std::string tag_to_remove);

public:
	// Public Wrapper Variables
	data_types const _DATA_TYPE;
	const enum class Type {
		// Use if want to create JSON list of all Admins.
		ALL_ADM,
		// Use if want to create JSON list of all Support agents.
		ALL_SUP,
		// Use if want to create JSON list of all Moderators.
		ALL_MOD,
		// Use if want to create JSON list of all Students.
		ALL_STU,
		// Use if want to create JSON list of all Employees.
		ALL_EMP,
		// Use if want to create JSON list of all Guests.
		ALL_GUE,
		// Use if want to create JSON list of all Networks.
		ALL_NET,
		// Use if want to create JSON list of all Stands.
		ALL_STD,
		// Use if want to create JSON list of all Cycles.
		ALL_CYC,
		// Use if want to create JSON list of all Locks.
		ALL_LCK,
		// Use if want to create JSON list of all Transactions.
		ALL_TXN,

		// Use if want to create JSON for Admin's data.
		ATR_ADM,
		// Use if want to create JSON for Support agent's data.
		ATR_SUP,
		// Use if want to create JSON for Moderator's data.
		ATR_MOD,
		// Use if want to create JSON for Student's data.
		ATR_STU,
		// Use if want to create JSON for Employee's data.
		ATR_EMP,
		// Use if want to create JSON for Guest's data.
		ATR_GUE,

		// Use if want to create JSON for Network's data.
		NET_STAT,
		// Use if want to create JSON list for Admins of a Network.
		NET_ADMS,
		// Use if want to create JSON list for Owner of a Network.
		NET_OWN,

		// Use if want to create JSON for basic Stand's data.
		NET_STD,
		// Use if want to create JSON for advanced Stand's data.
		NET_STD_STAT,
		// Use if want to create JSON for Nearest Stands.
		NET_NEAR_STD,
		// Use if want to create JSON for Vacant Stands.
		NET_STD_VACANT,

		// Use if want to create JSON for Cycle's data.
		NET_CYC,
		// Use if want to create JSON for Available Cycles.
		NET_CYC_FREE,

		// Use if want to create JSON for basic Lock's data.
		NET_LCK,
		// Use if want to create JSON for advanced Lock's data.
		NET_LCK_STAT,

		// Use if want to create JSON for Transaction data.
		TXN,
		// Use if want to create JSON for User's Transaction data.
		NET_USR_TXN,
		// Use if want to create JSON for Stand's Transaction data.
		NET_STD_TXN,
		// Use if want to create JSON for Cycle's Transaction data.
		NET_CYC_TXN
	};

public:
	// Public Methods

	~JSON();
	JSON(Type);

	std::string at(std::string TAG) const;
	void add(std::string custom_tag);
	void add(std::string custom_tag, std::string data);
	std::list<std::string> empty_tags();
	void fill_empty_tags(std::string fill_with = "0");
	bool has_empty_tag();
	void insert(std::string input_data);
	bool is_type(std::string given_type);
	size_t length() const;
	bool remove(std::string to_remove_tag);
	std::string serialize();
	std::list<std::string> tag_list();
	std::string type() const;
};

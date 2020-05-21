// HandleManager.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "core/resource/HandleEntry.h"
#include "core/resource/Handle.h"
#include "core/System.h"

#include <cassert>

constexpr U32 MaxEntries = 16384; // 2 ^ 14

class HandleManager : public System {
public:
	virtual ~HandleManager();

	virtual void Init();
	virtual void Update(sf::Time deltaTime);

	virtual IMessageHandler* GetParent() const;
	virtual void SendToChildren(const Message& msg);
	
	void Reset();
	Handle Add(void* ptr, U32 type);
	void Update(Handle handle, void* ptr);
	void Remove(Handle handle);

	void* Get(Handle handle) const;
	bool Get(Handle handle, void*& out) const;
	template<typename Type> bool GetAs(Handle handle, Type& out) const;

	int GetCount() const;	
	
private:
	HandleEntry m_entries[MaxEntries];
	U32 m_activeEntriesCount;
	U32 m_firstAvailableEntry;
	
};

template<typename Type>
inline bool HandleManager::GetAs(Handle handle, Type& out) const {
	void* outVoid;
	const bool isAvailable = Get(handle, outVoid);
	out = static_cast<Type>(outVoid);

	return isAvailable;
}
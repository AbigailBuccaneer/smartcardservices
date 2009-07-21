/*
 *  Copyright (c) 2004 Apple Computer, Inc. All Rights Reserved.
 * 
 *  @APPLE_LICENSE_HEADER_START@
 *  
 *  This file contains Original Code and/or Modifications of Original Code
 *  as defined in and that are subject to the Apple Public Source License
 *  Version 2.0 (the 'License'). You may not use this file except in
 *  compliance with the License. Please obtain a copy of the License at
 *  http://www.opensource.apple.com/apsl/ and read it before using this
 *  file.
 *  
 *  The Original Code and all software distributed under the License are
 *  distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 *  EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 *  INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 *  Please see the License for the specific language governing rights and
 *  limitations under the License.
 *  
 *  @APPLE_LICENSE_HEADER_END@
 */

/*
 *  SelectionPredicate.h
 *  TokendMuscle
 */

#ifndef _TOKEND_SELECTIONPREDICATE_H_
#define _TOKEND_SELECTIONPREDICATE_H_

#include <CoreServices/../Frameworks/CarbonCore.framework/Headers/MacTypes.h>
#include <security_cdsa_utilities/cssmdata.h>

namespace Tokend
{

class DbValue;
class MetaAttribute;
class MetaRecord;
class Record;
class TokenContext;

class SelectionPredicate
{
    NOCOPY(SelectionPredicate)
public:
    SelectionPredicate(const MetaRecord &inMetaRecord,
		const CSSM_SELECTION_PREDICATE &inPredicate);
	~SelectionPredicate();
	
	bool evaluate(TokenContext *tokenContext, Record& record) const;

private:
    const MetaAttribute &mMetaAttribute;
    CSSM_DB_OPERATOR mDbOperator;
	CssmDataContainer mData;
	DbValue *mValue;
};

} // end namespace Tokend

#endif /* !_TOKEND_SELECTIONPREDICATE_H_ */

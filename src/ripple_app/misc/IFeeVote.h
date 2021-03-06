//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef RIPPLE_IFEEVOTE_H
#define RIPPLE_IFEEVOTE_H

/** Manager to process fee votes.
*/
class IFeeVote
{
public:
    /** Create a new fee vote manager.

        @param targetBaseFee
        @param targetReserveBase
        @param targetReserveIncrement
    */
    static IFeeVote* New (uint64 targetBaseFee,
                          uint32 targetReserveBase,
                          uint32 targetReserveIncrement);

    virtual ~IFeeVote () { }

    /** Add local fee preference to validation.

        @param lastClosedLedger
        @param baseValidation
    */
    virtual void doValidation (Ledger::ref lastClosedLedger,
                               STObject& baseValidation) = 0;

    /** Cast our local vote on the fee.

        @param lastClosedLedger
        @param initialPosition
    */
    virtual void doVoting (Ledger::ref lastClosedLedger,
                           SHAMap::ref initialPosition) = 0;
};

#endif

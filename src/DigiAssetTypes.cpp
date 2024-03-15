//
// Created by mctrivia on 06/07/23.
//

#include <cstdint>
#include <vector>
#include "DigiAssetTypes.h"
#include "serialize.h"
#include "DigiAsset.h"


using namespace std;

Json::Value AssetUTXO::toJSON(bool simplified) const {
    Json::Value jsonUTXO;
    jsonUTXO["txid"] = txid;
    jsonUTXO["vout"] = vout;
    jsonUTXO["address"] = address;
    jsonUTXO["digibyte"] = static_cast<Json::UInt64>(digibyte);

    // Convert assets if present
    for (const auto& asset : assets) {
        jsonUTXO["assets"].append(asset.toJSON(simplified));
    }

    return jsonUTXO;
}

void serialize(vector<uint8_t>& serializedData, const Signer& input) {
    serialize(serializedData, input.address);
    serialize(serializedData, input.weight);
}

void deserialize(const vector<uint8_t>& serializedData, size_t& i, Signer& output) {
    deserialize(serializedData, i, output.address);
    deserialize(serializedData, i, output.weight);
}

void serialize(vector<uint8_t>& serializedData, const ExchangeRate& input) {
    serialize(serializedData, input.address);
    serialize(serializedData, input.index);
    serialize(serializedData, input.name);
}

void deserialize(const vector<uint8_t>& serializedData, size_t& i, ExchangeRate& output) {
    deserialize(serializedData, i, output.address);
    deserialize(serializedData, i, output.index);
    deserialize(serializedData, i, output.name);
}

void serialize(vector<uint8_t>& serializedData, const Royalty& input) {
    serialize(serializedData, input.address);
    serialize(serializedData, input.amount);
}

void deserialize(const vector<uint8_t>& serializedData, size_t& i, Royalty& output) {
    deserialize(serializedData, i, output.address);
    deserialize(serializedData, i, output.amount);
}

void serialize(vector<uint8_t>& serializedData, const VoteOption& input) {
    serialize(serializedData, input.address);
    serialize(serializedData, input.label);
}

void deserialize(const vector<uint8_t>& serializedData, size_t& i, VoteOption& output) {
    deserialize(serializedData, i, output.address);
    deserialize(serializedData, i, output.label);
}
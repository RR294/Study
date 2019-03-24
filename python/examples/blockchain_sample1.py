import hashlib, json

# First/Genesis block.
block_genesis = {
    'prev_hash' : None,
    'transaction' : ['Person A', 'Person B', 100.25]   # Person A paid Rs.100.25 to Person B.
}

# Second block.
block_2 = {
    'prev_hash' : None,
    'transaction' : ['Person B', 'Person C', 50.0]  # Person B paid Rs.50.0 to Person C
}

# Third block.
block_3 = {
    'prev_hash': None,
    'transaction': ['Person C', 'Person D', 45.0] # Person C paid Rs.45.0 to Person D.
}

# Function to hash blocks.
def hash_blocks(blocks):
    prev_hash = None

    # For eack block
    #   1. set it's prev hash
    #   2. generate it's new hash, which will be used as prev hash for next block.
    for block in blocks:
        block['prev_hash'] = prev_hash
        block_serialized = json.dumps(block, sort_keys=True).encode('utf-8')
        #print(block_serialized)
        block_hash = hashlib.sha256(block_serialized).hexdigest()
        prev_hash = block_hash

    return prev_hash

# Print hash with original transactions.
print(hash_blocks([block_genesis, block_2, block_3]))

# Now edit some information in them...
# For Ex. in genesis block change amount to 100.0
block_genesis['transaction'][2] = 100.0

# Print hash with modified transactions.
print(hash_blocks([block_genesis, block_2, block_3]))
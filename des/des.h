#ifndef _DES_H_
#define _DES_H_

enum { ENCRYPT, DECRYPT };

// 加密/解密 Type=ENCRYPT:加密,DECRYPT:解密
void Des_Run(char Out[8], char In[8], bool Type = ENCRYPT);
// 设置密钥
void Des_SetKey(const char Key[8]);

#endif

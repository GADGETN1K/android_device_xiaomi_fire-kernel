// SPDX-License-Identifier: GPL-2.0
/*
 * Recovery-only stand-in for the MediaTek alspshub driver.
 *
 * The touch drivers (fts_8720, nt36672c_spi, tpd_notify) link against
 * three proximity sensor hooks exported by alspshub. The real module
 * needs sensorHub and SCP, and SCP is disabled in recovery, so provide
 * no-op versions of the hooks instead.
 */
#include <linux/module.h>
#include <linux/notifier.h>

void *ps_tpd;
EXPORT_SYMBOL(ps_tpd);

int ps_enable_register_notifier(struct notifier_block *nb)
{
	return 0;
}
EXPORT_SYMBOL(ps_enable_register_notifier);

int ps_register_recive_touch_event_callback(void *cb)
{
	return 0;
}
EXPORT_SYMBOL(ps_register_recive_touch_event_callback);

static int __init alspshub_stub_init(void)
{
	return 0;
}
module_init(alspshub_stub_init);

MODULE_DESCRIPTION("alspshub stub for recovery");
MODULE_LICENSE("GPL");

export function by_id(id) {
    return by.id(id);
}

export function by_text(text) {
    return by.text(text);
}

export async function element_tap(by) {
    return await element(by).tap();
}

export async function detox_element_id_typeText(id, value) {
    return await element(by.id(id)).typeText(value);
}

export async function detox_expect_text_toBeVisible(text) {
    return await expect(element(by.text(text))).toBeVisible();
}

export async function detox_expect_id_toBeVisible(id) {
    return await expect(element(by.id(id))).toBeVisible();
}

export async function detox_expect_id_toExist(id) {
    return await expect(element(by.id(id))).toExist();
}

export async function detox_expect_id_toHaveText(id, expected) {
    return await expect(element(by.id(id))).toHaveText(expected);
}
